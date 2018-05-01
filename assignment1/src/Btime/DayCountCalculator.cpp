#include "DayCountCalculator.h"
/**
 * Implementacion de las clases para calcular el numero de dias a partir de dos fechas ya sean en string o mediante boost::gregorian::date
 */


//Actual_360 - compute_daycount_boost(bfrom, bto)
double
Actual_360::compute_daycount(const boost::gregorian::date &bfrom, const boost::gregorian::date &bto) const {
    return (bto - bfrom).days();
}

Actual_360::Actual_360() : DayCountCalculator(N_DAYS_ACTUAL_360) {}


//Thirty_360 - compute_daycount_1(years, months, days_from, days_to)
double Thirty_360::compute_daycount(const short years, const short months, const short days_from,
                                    const short days_to) const {
    return ((360 * years) + (30 * (months - 1)) + std::max<int>(0, (30 - days_from)) + std::min<int>(30, days_to));
}

//Thirty_360 - compute_daycount_boost(bfrom, bto)
double Thirty_360::compute_daycount(const boost::gregorian::date &bfrom, const boost::gregorian::date &bto) const {
    auto from_date{bfrom.year_month_day()};
    auto to_date{bto.year_month_day()};
    auto years = to_date.year - from_date.year;
    auto months = to_date.month - from_date.month;
    return compute_daycount(years, months, from_date.day, to_date.day);
}

Thirty_360::Thirty_360() : DayCountCalculator(N_DAYS_THIRTY_360)  { };
