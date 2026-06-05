#include <ql/time/calendars/china.hpp>
#include "time/calendar/mycalendar.hpp"
#include <iostream>
#include <cassert>

using namespace QuantLib;
using namespace MyQl;

// ============================================================================
// Build SSE holidays set from china.cpp data (2010-2026)
// Only non-weekend holiday dates need to be included, since MyCalendar
// handles weekends via bitmap automatically.
// ============================================================================
static std::set<Date> buildSseHolidays() {
    std::set<Date> holidays;

    // New Year's Day (non-weekend only)
    holidays.insert(Date(1, January, 2010));
    holidays.insert(Date(3, January, 2011));
    holidays.insert(Date(2, January, 2012));
    holidays.insert(Date(3, January, 2012));
    holidays.insert(Date(1, January, 2013));
    holidays.insert(Date(2, January, 2013));
    holidays.insert(Date(3, January, 2013));
    holidays.insert(Date(1, January, 2014));
    holidays.insert(Date(1, January, 2015));
    holidays.insert(Date(2, January, 2015));
    holidays.insert(Date(3, January, 2015));
    holidays.insert(Date(1, January, 2016));
    holidays.insert(Date(2, January, 2017));
    holidays.insert(Date(1, January, 2018));
    holidays.insert(Date(31, December, 2018));
    holidays.insert(Date(1, January, 2019));
    holidays.insert(Date(1, January, 2020));
    holidays.insert(Date(1, January, 2021));
    holidays.insert(Date(3, January, 2022));
    holidays.insert(Date(2, January, 2023));
    holidays.insert(Date(1, January, 2024));
    holidays.insert(Date(1, January, 2025));
    holidays.insert(Date(1, January, 2026));
    holidays.insert(Date(2, January, 2026));

    // Chinese New Year (non-weekend only)
    holidays.insert(Date(15, February, 2010));
    holidays.insert(Date(16, February, 2010));
    holidays.insert(Date(17, February, 2010));
    holidays.insert(Date(18, February, 2010));
    holidays.insert(Date(19, February, 2010));
    holidays.insert(Date(2, February, 2011));
    holidays.insert(Date(3, February, 2011));
    holidays.insert(Date(4, February, 2011));
    holidays.insert(Date(5, February, 2011));
    holidays.insert(Date(6, February, 2011));
    holidays.insert(Date(7, February, 2011));
    holidays.insert(Date(8, February, 2011));
    holidays.insert(Date(23, January, 2012));
    holidays.insert(Date(24, January, 2012));
    holidays.insert(Date(25, January, 2012));
    holidays.insert(Date(26, January, 2012));
    holidays.insert(Date(27, January, 2012));
    holidays.insert(Date(28, January, 2012));
    holidays.insert(Date(11, February, 2013));
    holidays.insert(Date(12, February, 2013));
    holidays.insert(Date(13, February, 2013));
    holidays.insert(Date(14, February, 2013));
    holidays.insert(Date(15, February, 2013));
    holidays.insert(Date(31, January, 2014));
    holidays.insert(Date(1, February, 2014));
    holidays.insert(Date(2, February, 2014));
    holidays.insert(Date(3, February, 2014));
    holidays.insert(Date(4, February, 2014));
    holidays.insert(Date(5, February, 2014));
    holidays.insert(Date(6, February, 2014));
    holidays.insert(Date(18, February, 2015));
    holidays.insert(Date(19, February, 2015));
    holidays.insert(Date(20, February, 2015));
    holidays.insert(Date(21, February, 2015));
    holidays.insert(Date(22, February, 2015));
    holidays.insert(Date(23, February, 2015));
    holidays.insert(Date(24, February, 2015));
    holidays.insert(Date(8, February, 2016));
    holidays.insert(Date(9, February, 2016));
    holidays.insert(Date(10, February, 2016));
    holidays.insert(Date(11, February, 2016));
    holidays.insert(Date(12, February, 2016));
    holidays.insert(Date(27, January, 2017));
    holidays.insert(Date(28, January, 2017));
    holidays.insert(Date(29, January, 2017));
    holidays.insert(Date(30, January, 2017));
    holidays.insert(Date(31, January, 2017));
    holidays.insert(Date(1, February, 2017));
    holidays.insert(Date(2, February, 2017));
    holidays.insert(Date(15, February, 2018));
    holidays.insert(Date(16, February, 2018));
    holidays.insert(Date(17, February, 2018));
    holidays.insert(Date(18, February, 2018));
    holidays.insert(Date(19, February, 2018));
    holidays.insert(Date(20, February, 2018));
    holidays.insert(Date(21, February, 2018));
    holidays.insert(Date(4, February, 2019));
    holidays.insert(Date(5, February, 2019));
    holidays.insert(Date(6, February, 2019));
    holidays.insert(Date(7, February, 2019));
    holidays.insert(Date(8, February, 2019));
    holidays.insert(Date(24, January, 2020));
    holidays.insert(Date(27, January, 2020));
    holidays.insert(Date(28, January, 2020));
    holidays.insert(Date(29, January, 2020));
    holidays.insert(Date(30, January, 2020));
    holidays.insert(Date(31, January, 2020));
    holidays.insert(Date(11, February, 2021));
    holidays.insert(Date(12, February, 2021));
    holidays.insert(Date(15, February, 2021));
    holidays.insert(Date(16, February, 2021));
    holidays.insert(Date(17, February, 2021));
    holidays.insert(Date(31, January, 2022));
    holidays.insert(Date(1, February, 2022));
    holidays.insert(Date(2, February, 2022));
    holidays.insert(Date(3, February, 2022));
    holidays.insert(Date(4, February, 2022));
    holidays.insert(Date(23, January, 2023));
    holidays.insert(Date(24, January, 2023));
    holidays.insert(Date(25, January, 2023));
    holidays.insert(Date(26, January, 2023));
    holidays.insert(Date(27, January, 2023));
    holidays.insert(Date(9, February, 2024));
    holidays.insert(Date(12, February, 2024));
    holidays.insert(Date(13, February, 2024));
    holidays.insert(Date(14, February, 2024));
    holidays.insert(Date(15, February, 2024));
    holidays.insert(Date(16, February, 2024));
    holidays.insert(Date(28, January, 2025));
    holidays.insert(Date(29, January, 2025));
    holidays.insert(Date(30, January, 2025));
    holidays.insert(Date(31, January, 2025));
    holidays.insert(Date(3, February, 2025));
    holidays.insert(Date(4, February, 2025));
    holidays.insert(Date(16, February, 2026));
    holidays.insert(Date(17, February, 2026));
    holidays.insert(Date(18, February, 2026));
    holidays.insert(Date(19, February, 2026));
    holidays.insert(Date(20, February, 2026));
    holidays.insert(Date(23, February, 2026));

    // Ching Ming Festival (non-weekend only)
    holidays.insert(Date(5, April, 2010));
    holidays.insert(Date(5, April, 2011));
    holidays.insert(Date(4, April, 2011));
    holidays.insert(Date(3, April, 2011));
    holidays.insert(Date(2, April, 2012));
    holidays.insert(Date(3, April, 2012));
    holidays.insert(Date(4, April, 2012));
    holidays.insert(Date(4, April, 2013));
    holidays.insert(Date(5, April, 2013));
    holidays.insert(Date(7, April, 2014));
    holidays.insert(Date(6, April, 2015));
    holidays.insert(Date(5, April, 2015));
    holidays.insert(Date(4, April, 2016));
    holidays.insert(Date(3, April, 2017));
    holidays.insert(Date(4, April, 2017));
    holidays.insert(Date(5, April, 2018));
    holidays.insert(Date(6, April, 2018));
    holidays.insert(Date(5, April, 2019));
    holidays.insert(Date(6, April, 2020));
    holidays.insert(Date(5, April, 2021));
    holidays.insert(Date(4, April, 2022));
    holidays.insert(Date(5, April, 2022));
    holidays.insert(Date(5, April, 2023));
    holidays.insert(Date(4, April, 2024));
    holidays.insert(Date(5, April, 2024));
    holidays.insert(Date(4, April, 2025));
    holidays.insert(Date(6, April, 2026));

    // Labor Day (non-weekend only)
    holidays.insert(Date(3, May, 2010));
    holidays.insert(Date(2, May, 2011));
    holidays.insert(Date(30, April, 2012));
    holidays.insert(Date(1, May, 2012));
    holidays.insert(Date(29, April, 2013));
    holidays.insert(Date(30, April, 2013));
    holidays.insert(Date(1, May, 2013));
    holidays.insert(Date(1, May, 2014));
    holidays.insert(Date(2, May, 2014));
    holidays.insert(Date(3, May, 2014));
    holidays.insert(Date(1, May, 2015));
    holidays.insert(Date(1, May, 2016));
    holidays.insert(Date(2, May, 2016));
    holidays.insert(Date(1, May, 2017));
    holidays.insert(Date(30, April, 2018));
    holidays.insert(Date(1, May, 2018));
    holidays.insert(Date(1, May, 2019));
    holidays.insert(Date(2, May, 2019));
    holidays.insert(Date(3, May, 2019));
    holidays.insert(Date(1, May, 2020));
    holidays.insert(Date(4, May, 2020));
    holidays.insert(Date(5, May, 2020));
    holidays.insert(Date(3, May, 2021));
    holidays.insert(Date(4, May, 2021));
    holidays.insert(Date(5, May, 2021));
    holidays.insert(Date(2, May, 2022));
    holidays.insert(Date(3, May, 2022));
    holidays.insert(Date(4, May, 2022));
    holidays.insert(Date(1, May, 2023));
    holidays.insert(Date(2, May, 2023));
    holidays.insert(Date(3, May, 2023));
    holidays.insert(Date(1, May, 2024));
    holidays.insert(Date(2, May, 2024));
    holidays.insert(Date(3, May, 2024));
    holidays.insert(Date(1, May, 2025));
    holidays.insert(Date(2, May, 2025));
    holidays.insert(Date(5, May, 2025));
    holidays.insert(Date(1, May, 2026));
    holidays.insert(Date(4, May, 2026));
    holidays.insert(Date(5, May, 2026));

    // Tuen Ng Festival (non-weekend only)
    holidays.insert(Date(14, June, 2010));
    holidays.insert(Date(15, June, 2010));
    holidays.insert(Date(16, June, 2010));
    holidays.insert(Date(4, June, 2011));
    holidays.insert(Date(5, June, 2011));
    holidays.insert(Date(6, June, 2011));
    holidays.insert(Date(22, June, 2012));
    holidays.insert(Date(23, June, 2012));
    holidays.insert(Date(24, June, 2012));
    holidays.insert(Date(10, June, 2013));
    holidays.insert(Date(11, June, 2013));
    holidays.insert(Date(12, June, 2013));
    holidays.insert(Date(2, June, 2014));
    holidays.insert(Date(22, June, 2015));
    holidays.insert(Date(9, June, 2016));
    holidays.insert(Date(10, June, 2016));
    holidays.insert(Date(29, May, 2017));
    holidays.insert(Date(30, May, 2017));
    holidays.insert(Date(18, June, 2018));
    holidays.insert(Date(7, June, 2019));
    holidays.insert(Date(25, June, 2020));
    holidays.insert(Date(26, June, 2020));
    holidays.insert(Date(14, June, 2021));
    holidays.insert(Date(3, June, 2022));
    holidays.insert(Date(22, June, 2023));
    holidays.insert(Date(23, June, 2023));
    holidays.insert(Date(10, June, 2024));
    holidays.insert(Date(2, June, 2025));
    holidays.insert(Date(19, June, 2026));

    // Mid-Autumn Festival (non-weekend only)
    holidays.insert(Date(22, September, 2010));
    holidays.insert(Date(23, September, 2010));
    holidays.insert(Date(24, September, 2010));
    holidays.insert(Date(10, September, 2011));
    holidays.insert(Date(11, September, 2011));
    holidays.insert(Date(12, September, 2011));
    holidays.insert(Date(30, September, 2012));
    holidays.insert(Date(19, September, 2013));
    holidays.insert(Date(20, September, 2013));
    holidays.insert(Date(8, September, 2014));
    holidays.insert(Date(27, September, 2015));
    holidays.insert(Date(15, September, 2016));
    holidays.insert(Date(16, September, 2016));
    holidays.insert(Date(24, September, 2018));
    holidays.insert(Date(13, September, 2019));
    holidays.insert(Date(20, September, 2021));
    holidays.insert(Date(21, September, 2021));
    holidays.insert(Date(12, September, 2022));
    holidays.insert(Date(29, September, 2023));
    holidays.insert(Date(16, September, 2024));
    holidays.insert(Date(17, September, 2024));
    holidays.insert(Date(25, September, 2026));

    // National Day (non-weekend only)
    holidays.insert(Date(1, October, 2010));
    holidays.insert(Date(4, October, 2010));
    holidays.insert(Date(5, October, 2010));
    holidays.insert(Date(6, October, 2010));
    holidays.insert(Date(7, October, 2010));
    holidays.insert(Date(1, October, 2011));
    holidays.insert(Date(2, October, 2011));
    holidays.insert(Date(3, October, 2011));
    holidays.insert(Date(4, October, 2011));
    holidays.insert(Date(5, October, 2011));
    holidays.insert(Date(6, October, 2011));
    holidays.insert(Date(7, October, 2011));
    holidays.insert(Date(1, October, 2012));
    holidays.insert(Date(2, October, 2012));
    holidays.insert(Date(3, October, 2012));
    holidays.insert(Date(4, October, 2012));
    holidays.insert(Date(5, October, 2012));
    holidays.insert(Date(1, October, 2013));
    holidays.insert(Date(2, October, 2013));
    holidays.insert(Date(3, October, 2013));
    holidays.insert(Date(4, October, 2013));
    holidays.insert(Date(7, October, 2013));
    holidays.insert(Date(1, October, 2014));
    holidays.insert(Date(2, October, 2014));
    holidays.insert(Date(3, October, 2014));
    holidays.insert(Date(6, October, 2014));
    holidays.insert(Date(7, October, 2014));
    holidays.insert(Date(1, October, 2015));
    holidays.insert(Date(2, October, 2015));
    holidays.insert(Date(5, October, 2015));
    holidays.insert(Date(6, October, 2015));
    holidays.insert(Date(7, October, 2015));
    holidays.insert(Date(3, October, 2016));
    holidays.insert(Date(4, October, 2016));
    holidays.insert(Date(5, October, 2016));
    holidays.insert(Date(6, October, 2016));
    holidays.insert(Date(7, October, 2016));
    holidays.insert(Date(2, October, 2017));
    holidays.insert(Date(3, October, 2017));
    holidays.insert(Date(4, October, 2017));
    holidays.insert(Date(5, October, 2017));
    holidays.insert(Date(6, October, 2017));
    holidays.insert(Date(1, October, 2018));
    holidays.insert(Date(2, October, 2018));
    holidays.insert(Date(3, October, 2018));
    holidays.insert(Date(4, October, 2018));
    holidays.insert(Date(5, October, 2018));
    holidays.insert(Date(1, October, 2019));
    holidays.insert(Date(2, October, 2019));
    holidays.insert(Date(3, October, 2019));
    holidays.insert(Date(4, October, 2019));
    holidays.insert(Date(7, October, 2019));
    holidays.insert(Date(1, October, 2020));
    holidays.insert(Date(2, October, 2020));
    holidays.insert(Date(5, October, 2020));
    holidays.insert(Date(6, October, 2020));
    holidays.insert(Date(7, October, 2020));
    holidays.insert(Date(8, October, 2020));
    holidays.insert(Date(1, October, 2021));
    holidays.insert(Date(4, October, 2021));
    holidays.insert(Date(5, October, 2021));
    holidays.insert(Date(6, October, 2021));
    holidays.insert(Date(7, October, 2021));
    holidays.insert(Date(3, October, 2022));
    holidays.insert(Date(4, October, 2022));
    holidays.insert(Date(5, October, 2022));
    holidays.insert(Date(6, October, 2022));
    holidays.insert(Date(7, October, 2022));
    holidays.insert(Date(2, October, 2023));
    holidays.insert(Date(3, October, 2023));
    holidays.insert(Date(4, October, 2023));
    holidays.insert(Date(5, October, 2023));
    holidays.insert(Date(6, October, 2023));
    holidays.insert(Date(1, October, 2024));
    holidays.insert(Date(2, October, 2024));
    holidays.insert(Date(3, October, 2024));
    holidays.insert(Date(4, October, 2024));
    holidays.insert(Date(7, October, 2024));
    holidays.insert(Date(1, October, 2025));
    holidays.insert(Date(2, October, 2025));
    holidays.insert(Date(3, October, 2025));
    holidays.insert(Date(6, October, 2025));
    holidays.insert(Date(7, October, 2025));
    holidays.insert(Date(8, October, 2025));
    holidays.insert(Date(1, October, 2026));
    holidays.insert(Date(2, October, 2026));
    holidays.insert(Date(5, October, 2026));
    holidays.insert(Date(6, October, 2026));
    holidays.insert(Date(7, October, 2026));

    // 70th anniversary (non-weekend only)
    holidays.insert(Date(3, September, 2015));
    holidays.insert(Date(4, September, 2015));

    return holidays;
}

// ============================================================================
// Build working weekends set from china.cpp IB data (2010-2026)
// ============================================================================
static std::set<Date> buildWorkingWeekends() {
    static const std::set<Date> workingWeekends = {
        // 2010
        Date(20, February, 2010),
        Date(21, February, 2010),
        Date(12, June, 2010),
        Date(13, June, 2010),
        Date(19, September, 2010),
        Date(25, September, 2010),
        Date(26, September, 2010),
        Date(9, October, 2010),
        // 2011
        Date(30, January, 2011),
        Date(12, February, 2011),
        Date(2, April, 2011),
        Date(8, October, 2011),
        Date(9, October, 2011),
        Date(31, December, 2011),
        // 2012
        Date(21, January, 2012),
        Date(29, January, 2012),
        Date(31, March, 2012),
        Date(1, April, 2012),
        Date(28, April, 2012),
        Date(29, September, 2012),
        // 2013
        Date(5, January, 2013),
        Date(6, January, 2013),
        Date(16, February, 2013),
        Date(17, February, 2013),
        Date(7, April, 2013),
        Date(27, April, 2013),
        Date(28, April, 2013),
        Date(8, June, 2013),
        Date(9, June, 2013),
        Date(22, September, 2013),
        Date(29, September, 2013),
        Date(12, October, 2013),
        // 2014
        Date(26, January, 2014),
        Date(8, February, 2014),
        Date(4, May, 2014),
        Date(28, September, 2014),
        Date(11, October, 2014),
        // 2015
        Date(4, January, 2015),
        Date(15, February, 2015),
        Date(28, February, 2015),
        Date(6, September, 2015),
        Date(10, October, 2015),
        // 2016
        Date(6, February, 2016),
        Date(14, February, 2016),
        Date(12, June, 2016),
        Date(18, September, 2016),
        Date(8, October, 2016),
        Date(9, October, 2016),
        // 2017
        Date(22, January, 2017),
        Date(4, February, 2017),
        Date(1, April, 2017),
        Date(27, May, 2017),
        Date(30, September, 2017),
        // 2018
        Date(11, February, 2018),
        Date(24, February, 2018),
        Date(8, April, 2018),
        Date(28, April, 2018),
        Date(29, September, 2018),
        Date(30, September, 2018),
        Date(29, December, 2018),
        // 2019
        Date(2, February, 2019),
        Date(3, February, 2019),
        Date(28, April, 2019),
        Date(5, May, 2019),
        Date(29, September, 2019),
        Date(12, October, 2019),
        // 2020
        Date(19, January, 2020),
        Date(26, April, 2020),
        Date(9, May, 2020),
        Date(28, June, 2020),
        Date(27, September, 2020),
        Date(10, October, 2020),
        // 2021
        Date(7, February, 2021),
        Date(20, February, 2021),
        Date(25, April, 2021),
        Date(8, May, 2021),
        Date(18, September, 2021),
        Date(26, September, 2021),
        Date(9, October, 2021),
        // 2022
        Date(29, January, 2022),
        Date(30, January, 2022),
        Date(2, April, 2022),
        Date(24, April, 2022),
        Date(7, May, 2022),
        Date(8, October, 2022),
        Date(9, October, 2022),
        // 2023
        Date(28, January, 2023),
        Date(29, January, 2023),
        Date(23, April, 2023),
        Date(6, May, 2023),
        Date(25, June, 2023),
        Date(7, October, 2023),
        Date(8, October, 2023),
        // 2024
        Date(4, February, 2024),
        Date(9, February, 2024),
        Date(18, February, 2024),
        Date(7, April, 2024),
        Date(28, April, 2024),
        Date(11, May, 2024),
        Date(14, September, 2024),
        Date(29, September, 2024),
        Date(12, October, 2024),
        // 2025
        Date(26, January, 2025),
        Date(8, February, 2025),
        Date(27, April, 2025),
        Date(28, September, 2025),
        Date(11, October, 2025),
        // 2026
        Date(4, January, 2026),
        Date(14, February, 2026),
        Date(28, February, 2026),
        Date(9, May, 2026),
        Date(20, September, 2026),
        Date(10, October, 2026)
    };
    return workingWeekends;
}

// ============================================================================
// Test: MySSEImpl vs QuantLib::China(SSE)
// ============================================================================
void testSSE() {
    auto holidays = buildSseHolidays();
    MyCalendar mySse(holidays, MyCalendar::SSE);
    China qlSse(China::SSE);

    int passCount = 0;
    int failCount = 0;

    // Test every day in 2010-2026
    for (Year y = 2010; y <= 2026; ++y) {
        for (Month m = January; m <= December; m = static_cast<Month>(m + 1)) {
            Date endOfMonthDate = Date::endOfMonth(Date(1, m, y));
            int daysInMonth = static_cast<int>(endOfMonthDate.dayOfMonth());
            for (int d = 1; d <= daysInMonth; ++d) {
                Date date(d, m, y);
                bool myResult = mySse.isBusinessDay(date);
                bool qlResult = qlSse.isBusinessDay(date);
                if (myResult != qlResult) {
                    std::cout << "SSE FAIL: " << date
                              << " MyCalendar=" << myResult
                              << " China=" << qlResult << std::endl;
                    ++failCount;
                } else {
                    ++passCount;
                }
            }
        }
    }

    std::cout << "SSE test: " << passCount << " passed, " << failCount << " failed" << std::endl;
}

// ============================================================================
// Test: MyIbImpl vs QuantLib::China(IB)
// ============================================================================
void testIB() {
    auto holidays = buildSseHolidays();
    auto workingWeekends = buildWorkingWeekends();
    MyCalendar myIb(holidays, workingWeekends, MyCalendar::IB);
    China qlIb(China::IB);

    int passCount = 0;
    int failCount = 0;

    // Test every day in 2010-2026
    for (Year y = 2010; y <= 2026; ++y) {
        for (Month m = January; m <= December; m = static_cast<Month>(m + 1)) {
            Date endOfMonthDate = Date::endOfMonth(Date(1, m, y));
            int daysInMonth = static_cast<int>(endOfMonthDate.dayOfMonth());
            for (int d = 1; d <= daysInMonth; ++d) {
                Date date(d, m, y);
                bool myResult = myIb.isBusinessDay(date);
                bool qlResult = qlIb.isBusinessDay(date);
                if (myResult != qlResult) {
                    std::cout << "IB FAIL: " << date
                              << " MyCalendar=" << myResult
                              << " China=" << qlResult << std::endl;
                    ++failCount;
                } else {
                    ++passCount;
                }
            }
        }
    }

    std::cout << "IB test: " << passCount << " passed, " << failCount << " failed" << std::endl;
}

// ============================================================================
// Test: Out-of-range dates (before startDate_ or after endDate_)
//       Only weekends should be treated as holidays.
// ============================================================================
void testOutOfRange() {
    auto holidays = buildSseHolidays();
    MyCalendar mySse(holidays, MyCalendar::SSE);

    int passCount = 0;
    int failCount = 0;

    // Test 2009-01-01 ~ 2009-12-31 (before the holiday range starts)
    for (Month m = January; m <= December; m = static_cast<Month>(m + 1)) {
        Date endOfMonthDate = Date::endOfMonth(Date(1, m, 2009));
        int daysInMonth = static_cast<int>(endOfMonthDate.dayOfMonth());
        for (int d = 1; d <= daysInMonth; ++d) {
            Date date(d, m, 2009);
            Weekday w = date.weekday();
            bool expected = (w != Saturday && w != Sunday);  // only weekend = holiday
            bool actual = mySse.isBusinessDay(date);
            if (actual != expected) {
                std::cout << "OUT-OF-RANGE FAIL (before): " << date
                          << " weekday=" << w
                          << " expected=" << expected
                          << " actual=" << actual << std::endl;
                ++failCount;
            } else {
                ++passCount;
            }
        }
    }

    // Test 2027-01-01 ~ 2027-12-31 (after the holiday range ends)
    for (Month m = January; m <= December; m = static_cast<Month>(m + 1)) {
        Date endOfMonthDate = Date::endOfMonth(Date(1, m, 2027));
        int daysInMonth = static_cast<int>(endOfMonthDate.dayOfMonth());
        for (int d = 1; d <= daysInMonth; ++d) {
            Date date(d, m, 2027);
            Weekday w = date.weekday();
            bool expected = (w != Saturday && w != Sunday);
            bool actual = mySse.isBusinessDay(date);
            if (actual != expected) {
                std::cout << "OUT-OF-RANGE FAIL (after): " << date
                          << " weekday=" << w
                          << " expected=" << expected
                          << " actual=" << actual << std::endl;
                ++failCount;
            } else {
                ++passCount;
            }
        }
    }

    std::cout << "Out-of-range test: " << passCount << " passed, " << failCount << " failed" << std::endl;
}

// ============================================================================
// Main
// ============================================================================
int main() {
    std::cout << "=== MyCalendar vs China(SSE) ===" << std::endl;
    testSSE();
    std::cout << std::endl;

    std::cout << "=== MyCalendar vs China(IB) ===" << std::endl;
    testIB();
    std::cout << std::endl;

    std::cout << "=== Out-of-range dates ===" << std::endl;
    testOutOfRange();

    return 0;
}
