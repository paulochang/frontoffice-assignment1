#ifndef UTILS_H
#define UTILS_H

double add(double f, int total);

double continuous_discount_factor(double continuous_rate, int years);

double annual_discount_factor(double annual_rate, int years);

double period_discount_factor(double annual_rate, int periods_per_year, int years);

double annual_discount(double amount, double annual_rate, int years);

double period_discount(double amount, double annual_rate, int periods_per_year, int years);

double continuous_discount(double amount, double continuous_rate, int years);

double annual_capitalization(double amount, double annual_rate, int years);

double period_capitalization(double amount, double annual_rate, int periods_per_year, int years);

double continuous_capitalization(double amount, double continuous_rate, int years);

double forward_rate(double zero_coupon_total, double years_total, double zero_coupon_partial, double years_partial);

double annual_to_continuous_rate(int periods_per_year, double annual_rate);

double continuous_to_annual_rate(int periods_per_year, double continuous_rate);

#endif 
