#define BOOST_TEST_MODULE test_btime

#include <boost/test/unit_test.hpp>
#include "Btime/DayCountCalculator.h"

BOOST_AUTO_TEST_SUITE(btime_test_suite)

    BOOST_AUTO_TEST_CASE(actual_count) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        const std::string from_date = "2001-12-25";
        const std::string to_date = "2002-1-1";
        DayCountCalculator *myCalc;
        Actual_360 actualCalc = Actual_360{};
        myCalc = &actualCalc;
        double calculated_values = myCalc->compute_daycount(from_date, to_date);
        double expected_values = 7.0;

        BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST_MESSAGE(" - Diff " << calculated_values - expected_values);
        BOOST_TEST(expected_values == calculated_values, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(thirty_count) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        const std::string from_date = "2001-12-25";
        const std::string to_date = "2002-1-1";
        DayCountCalculator *myCalc;
        Thirty_360 thirty360Calc = Thirty_360{};
        myCalc = &thirty360Calc;
        double calculated_values = myCalc->compute_daycount(from_date, to_date);
        double expected_values = 6.0;

        BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST_MESSAGE(" - Diff " << calculated_values - expected_values);
        BOOST_TEST(expected_values == calculated_values, boost::test_tools::tolerance(1e-15));
    }

BOOST_AUTO_TEST_SUITE_END()
