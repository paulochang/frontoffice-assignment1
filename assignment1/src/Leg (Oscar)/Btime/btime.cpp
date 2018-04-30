#include "btime.h"
/**
 * Implementacion de las clases para calcular el numero de dias a partir de dos fechas ya sean en string o mediante boost::gregorian::date
 */
 
//DayCountCalculator - etNDaysYear
int DayCountCalculator::getNDaysYear() {
	 return nDaysYear;
}

//Thirty_360 - compute_daycount(years, months, days_from, days_to)
double Thirty_360::compute_daycount(const short years, const short months, const short days_from, const short days_to) {
	return ((360 * years) + (30 * (months - 1)) + std::max<short>(0, (30 - days_from)) + std::min<short>(30, days_to));
}

//Thirty_360 - compute_daycount(from, to) (boost::gregorian::date)
double Thirty_360::compute_daycount(const boost::gregorian::date& from, const boost::gregorian::date& to) {
	auto from_date{from.year_month_day()};
	auto to_date{to.year_month_day()};
	auto years = to_date.year - from_date.year;
	auto months = to_date.month - from_date.month;
	return compute_daycount(years, months, from_date.day, to_date.day);
}

//Actual_360 - compute_daycount(from, to) (boost::gregorian::date)
double Actual_360::compute_daycount(const boost::gregorian::date& from, const boost::gregorian::date& to) {
	return (to - from).days();
}

//DayCountCalculator - compute_daycount(from, to) (std::string)
double DayCountCalculator::compute_daycount(const std::string& from, const std::string& to) {
	boost::gregorian::date from_date{boost::gregorian::from_string(from)};
	boost::gregorian::date to_date{boost::gregorian::from_string(to)};
	return compute_daycount(from_date, to_date);
}