#define BOOST_TEST_MODULE test_tir

#include "Leg/FixedLeg.h"
#include <Leg/ZeroCurve/ZeroCouponCurve.h>
#include <boost/test/unit_test.hpp>
#include <Tir/Tir.h>

namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(tir_test_suite)

/*
    BOOST_AUTO_TEST_CASE(actual_count) {
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
        ZeroCouponCurve zeroCouponCurve {};
        Tir tir = Tir(notional, rate, referenceDates, actualCalc);

        //Tir tir = Tir();

        double expected_values = 6.76;

        double calculated_values = tir.Get_Tir(6.76, 0.2);

        BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST_MESSAGE(" - Diff " << calculated_values - expected_values);
        BOOST_TEST(expected_values == calculated_values, boost::test_tools::tolerance(1e-15));
    }*/


BOOST_AUTO_TEST_SUITE_END()
