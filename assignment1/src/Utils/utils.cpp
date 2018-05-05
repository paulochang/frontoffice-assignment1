#include "utils.h"
#include <cmath>

double add(double f, int total) {
    double sum = 0.0;
    for (int i = 0; i < total; ++i) {
        sum += f;
    }
    return sum;
}

double continuous_discount_factor(double continuous_rate, int years) {
    return exp(-1 * continuous_rate * years);
}

double annual_discount_factor(double annual_rate, int years) {
    double cap_per_year = 1 + annual_rate;
    return pow(cap_per_year, -years);
}

double period_discount_factor(double annual_rate, int periods_per_year, int years) {
    double cap_per_period = (1 + annual_rate / periods_per_year);
    double total_periods = periods_per_year * years;
    return pow(cap_per_period, -total_periods);
}

double annual_capitalization(double amount, double annual_rate, int years) {
    double capitalization_rate = 1.0/annual_discount_factor(annual_rate, years);
    double result = amount * capitalization_rate;
    return result;
}

double period_capitalization(double amount, double annual_rate, int periods_per_year, int years) {
    double capitalization_rate = 1.0/period_discount_factor(annual_rate, periods_per_year, years);
    double result = amount * capitalization_rate;
    return result;
}

double continuous_capitalization(double amount, double continuous_rate, int years) {
    double capitalization_rate = 1.0/continuous_discount_factor(continuous_rate, years);
    double result = amount * capitalization_rate;
    return result;
}

double forward_rate(double zero_coupon_total, double years_total, double zero_coupon_partial, double years_partial) {
    double diff_performance = zero_coupon_total * years_total - zero_coupon_partial * years_partial;
    double diff_periods = years_total - years_partial;
    return diff_performance / diff_periods;
}

double annual_to_continuous_rate(int periods_per_year, double annual_rate) {
    return periods_per_year * log(1 + annual_rate / periods_per_year);
}

double continuous_to_annual_rate(int periods_per_year, double continuous_rate) {
    return periods_per_year * (exp(continuous_rate / periods_per_year) - 1);
}
