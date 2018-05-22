#define BOOST_TEST_MODULE test_utils

#include <boost/test/unit_test.hpp>
#include <Utils/utils.h>

BOOST_AUTO_TEST_SUITE(utils_boost)

    BOOST_AUTO_TEST_CASE(hello_world) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double f = 0.1;
        auto sum = add(f, 10);

        auto product = f * 10;

        BOOST_TEST_MESSAGE(" - sum: " << sum);
        BOOST_TEST_MESSAGE(" - product: " << product);
        BOOST_TEST_MESSAGE(" - diff " << sum - product);
        BOOST_TEST(sum == product, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(hello_world2) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double f = 0.1;
        auto sum = add(f, 10);

        auto product = f * 10;

        BOOST_TEST_MESSAGE(" - sum: " << sum);
        BOOST_TEST_MESSAGE(" - product: " << product);
        BOOST_TEST_MESSAGE(" - diff " << sum - product);
        BOOST_TEST(sum == product, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(annual_cap1) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double amount = 100;
        double annual_rate = 10.0 / 100;
        int number_of_years = 2;
        double theoretical_value = 121; // (100*(1.1)^2)

        auto calculated_value = annual_capitalization(amount, annual_rate, number_of_years);

        BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
        BOOST_TEST_MESSAGE(" - known_capitalization: " << theoretical_value);
        BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
        BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(period_cap1) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double amount = 100;
        double annual_rate = 10.0 / 100;
        int periods_per_year = 2;
        int number_of_years = 1;
        double theoretical_value = 110.25; // (100*(1.0.5)^2)

        auto calculated_value = period_capitalization(amount, annual_rate, periods_per_year, number_of_years);

        BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
        BOOST_TEST_MESSAGE(" - known_capitalization: " << theoretical_value);
        BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
        BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(continuous_cap1) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double amount = 100;
        double annual_rate = 10.0 / 100;
        int number_of_years = 2;
        double theoretical_value = 122.140275816; // (100*(1.1)^2) rounded to second

        auto calculated_value = continuous_capitalization(amount, annual_rate, number_of_years);

        BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
        BOOST_TEST_MESSAGE(" - known_capitalization: " << theoretical_value);
        BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
        BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-8));
    }

    BOOST_AUTO_TEST_CASE(fwd_rate1) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double zero_coupon_total = 0.04;
        int years_total = 2;

        double zero_coupon_partial = 0.03;
        int years_partial = 1;

        double theoretical_value = 0.05; // (100*(1.1)^2) rounded to second

        auto calculated_value = forward_rate(zero_coupon_total, years_total, zero_coupon_partial, years_partial);

        BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
        BOOST_TEST_MESSAGE(" - known_fwd_rate: " << theoretical_value);
        BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
        BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-15));
    }

    BOOST_AUTO_TEST_CASE(annual_to_cont1) {
            BOOST_TEST_MESSAGE("using tolerances within checks.");

            double annual_rate = 0.12;

            double theoretical_value = 0.1133286853; // ln(1.12)

            auto calculated_value = annual_to_continuous_rate(1, annual_rate);

            BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
            BOOST_TEST_MESSAGE(" - known_fwd_rate: " << theoretical_value);
            BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
            BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-10));
    }

    BOOST_AUTO_TEST_CASE(cont_to_annual) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");

        double continuous_rate = 0.11332868531; //(e^0.1)-1

        double theoretical_value = 0.12; // (e^0.1)-1

        auto calculated_value = continuous_to_annual_rate(1, continuous_rate);

        BOOST_TEST_MESSAGE(" - calculated_value: " << calculated_value);
        BOOST_TEST_MESSAGE(" - known_fwd_rate: " << theoretical_value);
        BOOST_TEST_MESSAGE(" - diff " << calculated_value - theoretical_value);
        BOOST_TEST(theoretical_value == calculated_value, boost::test_tools::tolerance(1e-9));
    }

    /*
    BOOST_AUTO_TEST_CASE(actual_count) {
        BOOST_TEST_MESSAGE("using tolerances within checks.");


			  const double notional = 100;
				const std::vector<double> CashFlows = {2.99, 2.98, 2.97, 101.60};
				const int sPeriods = 2;
			  const double tPPeriods = 2.0;
				const int mPeriod = 1;

				//Bono_TIR bond = Bono_TIR(notional, CashFlows, sPeriods, tPPeriods, mPeriod);

				//Bono_TIR bond = Bono_TIR();

				double expected_values = 	6.76;
				//double calculated_values = bond(notional, CashFlows, sPeriods, tPPeriods, mPeriod);

				double calculated_values = bond.cbrt(6.76);

        BOOST_TEST_MESSAGE(" - Calculated Value: " << calculated_values);
        BOOST_TEST_MESSAGE(" - Expected Value: " << expected_values);
        BOOST_TEST_MESSAGE(" - Diff " << calculated_values - expected_values);
        BOOST_TEST(expected_values == calculated_values, boost::test_tools::tolerance(1e-15));
    }*/


BOOST_AUTO_TEST_SUITE_END()
