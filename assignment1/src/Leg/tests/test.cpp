#define BOOST_TEST_MODULE test_leg


#include <boost/test/unit_test.hpp>
#include "Leg/FixedLeg.h"

namespace utf = boost::unit_test;


BOOST_AUTO_TEST_SUITE(leg_test_suite)

    BOOST_AUTO_TEST_CASE(fixed_day_fraction, * utf::tolerance(0.0000001)) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        const double notional = 100;
        const double rate = 5.0/100;
        std::vector<boost::gregorian::date> referenceDates {};
        referenceDates.push_back(boost::gregorian::from_string("2016-04-01"));
        referenceDates.push_back(boost::gregorian::from_string("2016-10-03"));
        referenceDates.push_back(boost::gregorian::from_string("2017-04-03"));
        referenceDates.push_back(boost::gregorian::from_string("2017-10-02"));
        referenceDates.push_back(boost::gregorian::from_string("2018-04-02"));

        Actual_360 actualCalc = Actual_360();

        FixedLeg myLeg {notional, rate, referenceDates, actualCalc};
        std::vector<double> calculated_values = myLeg.getDayCountFractionVector();

        double myDoubles[] = {0.513888888, 0.505555555, 0.505555555, 0.505555555 };
        std::vector<double> expected_values (myDoubles, myDoubles + sizeof(myDoubles) / sizeof(double) );


        //BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        //BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST(calculated_values == expected_values,  boost::test_tools::per_element());
    }

    BOOST_AUTO_TEST_CASE(fixed_cash_flows, * utf::tolerance(0.0001)) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        const double notional = 100;
        const double rate = 5.0/100;
        std::vector<boost::gregorian::date> referenceDates {};
        referenceDates.push_back(boost::gregorian::from_string("2016-04-01"));
        referenceDates.push_back(boost::gregorian::from_string("2016-10-03"));
        referenceDates.push_back(boost::gregorian::from_string("2017-04-03"));
        referenceDates.push_back(boost::gregorian::from_string("2017-10-02"));
        referenceDates.push_back(boost::gregorian::from_string("2018-04-02"));

        Actual_360 actualCalc = Actual_360();

        FixedLeg myLeg {notional, rate, referenceDates, actualCalc};

        double myDoubles[] = {0.51388888888, 0.505555555555, 0.505555555555, 0.505555555555 };
        std::vector<double> dayCountFractionVector (myDoubles, myDoubles + sizeof(myDoubles) / sizeof(double) );

        std::vector<double> calculated_values = myLeg.getLegCashFlows(dayCountFractionVector);

        double myResults[] = {2.569444, 2.527777, 2.527777, 2.527777};
        std::vector<double> expected_values (myResults, myResults + sizeof(myResults) / sizeof(double) );

        //BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        //BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST(calculated_values == expected_values,  boost::test_tools::per_element());
    }



BOOST_AUTO_TEST_SUITE_END()
