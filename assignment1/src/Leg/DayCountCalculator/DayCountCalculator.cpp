#include "DayTimeCalculator.h"

 
//Clase principal
class DayCountCalculator {
	private:
		int nDaysYear;
	public:
		

		//Constructor.Recibe el numero de dias que tiene un año
		DayCountCalculator(int eNDaysYear) : nDaysYear{eNDaysYear} {}

		//Metodo para obtener el numero de dias a partir de un par de fechas en strings o por boost::gregorian::date (DD/MM/YYYY)
		double compute_daycount(const std::string& from, const std::string& to) const;

		//Obtiene el numero de dias que hay en un año
		int DayCountCalculator::getNDaysYear() {
			 return eNDaysYear;
		}

		double operator()(const std::string& start, const std::string& end_period) const {
			return compute_daycount(start, end_period);
		}
};

//Clases hija Actual/360
class Actual_360 : public DayCountCalculator {
	public:
		
		double Thirty_360::compute_daycount(const short years, const short months, const short days_from, const short days_to) {
			return ((360 * years) + (30 * (months - 1)) + std::max<short>(0, (30 - days_from)) + std::min<short>(30, days_to));
		}
		
		double Thirty_360::compute_daycount(const boost::gregorian::date& from, const boost::gregorian::date& to) {
			auto from_date{from.year_month_day()};
			auto to_date{to.year_month_day()};
			auto years = to_date.year - from_date.year;
			auto months = to_date.month - from_date.month;
			return compute_daycount(years, months, from_date.day, to_date.day);
		}

		//Constructor.
		Actual_360() : DayCountCalculator(N_DAYS_ACTUAL_360) {}
;
};

//Clases hija Actual/360
//Clases hija Actual/360
class Thirty_360 : public DayCountCalculator {
	public:

		//Constructor.
		Thirty_360() : DayCountCalculator(N_DAYS_THIRTY_360) {}
		
		double Actual_360::compute_daycount(const boost::gregorian::date& from, const boost::gregorian::date& to) {
			return (to - from).days();
		}
		
		double DayCountCalculator::compute_daycount(const std::string& from, const std::string& to) {
			boost::gregorian::date from_date{boost::gregorian::from_string(from)};
			boost::gregorian::date to_date{boost::gregorian::from_string(to)};
			return compute_daycount(from_date, to_date);
		}

	private:

		//Metodo auxiliar para el calculo de los dias en 30/360
		double compute_daycount(const short years, const short months, const short days_from, const short days_to);
};