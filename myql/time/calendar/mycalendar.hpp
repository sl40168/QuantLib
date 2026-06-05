#pragma once
#ifndef my_quantlib_chinese_calendar_hpp
#define my_quantlib_chinese_calendar_hpp

#include <ql/time/calendar.hpp>
#include <map>

using namespace QuantLib;

namespace MyQl {

	class MyCalendar : public Calendar {
      private:
          // Base implementation: shared bitmap logic for holidays + working weekends
          class MyBaseImpl : public Calendar::Impl {
            public:
                MyBaseImpl(const std::set<Date>& holidays,
                           const std::set<Date>& working_weekends);
                bool isWeekend(Weekday) const override;
                bool isBusinessDay(const Date&) const override;

            protected:
                Date startDate_, endDate_;
                // key: (year << 4) | month, value: bitmap
                // bit = 1 means holiday, bit = 0 means business day
                std::map<int, int> holidayMap_;
          };

          // SSE: working_weekends is empty, weekend is always holiday
          class MySSEImpl final : public MyBaseImpl {
            public:
                MySSEImpl(const std::set<Date>& holidays);
                std::string name() const override { return "My Shanghai stock exchange"; }
          };

          // IB: working_weekends may be non-empty
          class MyIbImpl final : public MyBaseImpl {
            public:
                MyIbImpl(const std::set<Date>& holidays,
                         const std::set<Date>& working_weekends);
                std::string name() const override { return "My China inter bank market"; }
          };

		public:
          enum Market {
              SSE,    // Shanghai stock exchange
              IB      // Interbank market
          };

          MyCalendar(const std::set<Date>& holidays,
                     Market market = SSE);
          MyCalendar(const std::set<Date>& holidays,
                     const std::set<Date>& working_weekends,
                     Market market = IB);
	};
}

#endif // !my_quantlib_chinese_calendar_hpp
