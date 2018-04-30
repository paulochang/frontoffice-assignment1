#ifndef BTIME_H
#define BTIME_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
/**
 * Clase que implementa un calculador de dias entre dos fechas usando un calendario gregoriano mediante la libreria
 * Boost.
 * Las fechas se pasan bien por string o bien por un objeto tipo boost::gregorian::date.
 * Tambien tiene un atributo llamado 'nDaysYear()' que indica el número de días que tiene un año (por ejemplo en el convenio 30/360 un año tiene 360 dias). Este
 * atributo sera inicializado por las clases hijas y se puede acceder a traves del metodo miembro 'getNDaysYear()'
 */
 
 //Constantes utiles
 const int N_DAYS_ACTUAL_360 = 360;
 const int N_DAYS_THIRTY_360 = 360;
 
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
		int getNDaysYear();

		double operator()(const std::string& start, const std::string& end_period) const {
			return compute_daycount(start, end_period);
		}
};

//Clases hija Actual/360
class Actual_360 : public DayCountCalculator {
	public:

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

	private:

		//Metodo auxiliar para el calculo de los dias en 30/360
		double compute_daycount(const short years, const short months, const short days_from, const short days_to);
};

#endif