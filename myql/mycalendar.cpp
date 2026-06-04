#include "pch.h"
#include "mycalendar.hpp"
#include <ql/errors.hpp>
#include <algorithm>

namespace MyQl {

    // ========================================================================
    // MyBaseImpl: shared logic for building holiday bitmap from holidays
    //             and working_weekends
    // ========================================================================

    MyCalendar::MyBaseImpl::MyBaseImpl(const std::set<Date>& holidays,
                                       const std::set<Date>& working_weekends) {

        // Default range: 2010/1/1 ~ 2050/12/31
        static const Date defaultStart(1, January, 2010);
        static const Date defaultEnd(31, December, 2050);

        // 1. Merge holidays and working_weekends, find min and max
        std::set<Date> allDates;
        allDates.insert(holidays.begin(), holidays.end());
        allDates.insert(working_weekends.begin(), working_weekends.end());

        if (allDates.empty()) {
            startDate_ = defaultStart;
            endDate_ = defaultEnd;
            return;
        }

        startDate_ = *allDates.begin();
        endDate_ = *allDates.rbegin();

        // Helper lambda to encode (year, month) into a single int key
        auto makeKey = [](Year y, Month m) -> int {
            return (static_cast<int>(y) << 4) | static_cast<int>(m);
        };

        Year startYear = startDate_.year();
        Month startMonth = startDate_.month();
        Year endYear = endDate_.year();
        Month endMonth = endDate_.month();

        Year y = startYear;
        Month m = startMonth;
        while (true) {
            int key = makeKey(y, m);
            int bitmap = 0;

            // Get days in month via endOfMonth
            Date endOfMonthDate = Date::endOfMonth(Date(1, m, y));
            int daysInMonth = static_cast<int>(endOfMonthDate.dayOfMonth());

            // 2.2: Set weekend days (Sat/Sun) to 1
            for (int d = 1; d <= daysInMonth; ++d) {
                Date date(d, m, y);
                Weekday w = date.weekday();
                if (w == Saturday || w == Sunday) {
                    bitmap |= (1 << (d - 1));
                }
            }

            // 2.3: Set holiday dates to 1
            for (const auto& h : holidays) {
                if (h.year() == y && h.month() == m) {
                    int d = static_cast<int>(h.dayOfMonth());
                    bitmap |= (1 << (d - 1));
                }
            }

            // 2.4: Set working_weekend dates to 0 (clear the weekend bit)
            for (const auto& ww : working_weekends) {
                if (ww.year() == y && ww.month() == m) {
                    int d = static_cast<int>(ww.dayOfMonth());
                    bitmap &= ~(1 << (d - 1));
                }
            }

            holidayMap_[key] = bitmap;

            // Advance to next month
            if (y == endYear && m == endMonth)
                break;
            if (m == December) {
                m = January;
                ++y;
            } else {
                m = static_cast<Month>(static_cast<int>(m) + 1);
            }
        }
    }

    bool MyCalendar::MyBaseImpl::isWeekend(Weekday w) const {
        return w == Saturday || w == Sunday;
    }

    bool MyCalendar::MyBaseImpl::isBusinessDay(const Date& date) const {
        // Check if date is within the pre-computed range
        if (date < startDate_ || date > endDate_) {
            // Outside range: fall back to simple weekend check
            Weekday w = date.weekday();
            return !(w == Saturday || w == Sunday);
        }

        Year y = date.year();
        Month m = date.month();
        int key = (static_cast<int>(y) << 4) | static_cast<int>(m);

        auto it = holidayMap_.find(key);
        if (it == holidayMap_.end()) {
            // Month not in map (shouldn't happen), fall back to weekend check
            Weekday w = date.weekday();
            return !(w == Saturday || w == Sunday);
        }

        int d = static_cast<int>(date.dayOfMonth());
        int bitmap = it->second;

        // Bit is 1 => holiday, bit is 0 => business day
        return (bitmap & (1 << (d - 1))) == 0;
    }

    // ========================================================================
    // MySSEImpl: SSE market, weekend is always holiday (no working_weekends)
    // ========================================================================

    MyCalendar::MySSEImpl::MySSEImpl(const std::set<Date>& holidays)
        : MyBaseImpl(holidays, std::set<Date>()) {
    }

    // ========================================================================
    // MyIbImpl: IB market, may have working_weekends
    // ========================================================================

    MyCalendar::MyIbImpl::MyIbImpl(const std::set<Date>& holidays,
                                   const std::set<Date>& working_weekends)
        : MyBaseImpl(holidays, working_weekends) {
    }

    // ========================================================================
    // MyCalendar constructors
    // ========================================================================

    MyCalendar::MyCalendar(const std::set<Date>& holidays, Market market) {
        switch (market) {
          case SSE:
            impl_ = ext::make_shared<MyCalendar::MySSEImpl>(holidays);
            break;
          case IB:
            impl_ = ext::make_shared<MyCalendar::MyIbImpl>(holidays, std::set<Date>());
            break;
          default:
            QL_FAIL("unknown market");
        }
    }

    MyCalendar::MyCalendar(const std::set<Date>& holidays,
                           const std::set<Date>& working_weekends,
                           Market market) {
        switch (market) {
          case SSE:
            // SSE ignores working_weekends
            impl_ = ext::make_shared<MyCalendar::MySSEImpl>(holidays);
            break;
          case IB:
            impl_ = ext::make_shared<MyCalendar::MyIbImpl>(holidays, working_weekends);
            break;
          default:
            QL_FAIL("unknown market");
        }
    }

}