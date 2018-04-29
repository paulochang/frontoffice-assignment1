#include "btime.h"
/**
 * Implementacion de las clases para calcular el numero de dias a partir de dos fechas ya sean en string o mediante boost::gregorian::date
 */


//Actual_360 - compute_daycount_boost(bfrom, bto)
double
Actual_360::compute_daycount(const boost::gregorian::date &bfrom, const boost::gregorian::date &bto) const {
	return (bto - bfrom).days();
}

//Thirty_360 - compute_daycount_1(years, months, days_from, days_to)
double Thirty_360::compute_daycount(const short years, const short months, const short days_from,
									  const short days_to) const {
	return ((360 * years) + (30 * (months - 1)) + std::max<int>(0, (30 - days_from)) + std::min<int>(30, days_to));
}

//Thirty_360 - compute_daycount_boost(bfrom, bto)
double
Thirty_360::compute_daycount(const boost::gregorian::date &bfrom, const boost::gregorian::date &bto) const {
	auto from_date{bfrom.year_month_day()};
	auto to_date{bto.year_month_day()};
	auto years = to_date.year - from_date.year;
	auto months = to_date.month - from_date.month;
	return compute_daycount(years, months, from_date.day, to_date.day);
}

//DayCountCalculator - compute_daycount(string_from, string_to)
double DayCountCalculator::compute_daycount(const std::string &string_from, const std::string &string_to) const {
	boost::gregorian::date from_date{boost::gregorian::from_string(string_from)};
	boost::gregorian::date to_date{boost::gregorian::from_string(string_to)};
	return compute_daycount(from_date, to_date);
}

int DayCountCalculator::getNDaysYear() {
	return this->nDaysYear;
}
