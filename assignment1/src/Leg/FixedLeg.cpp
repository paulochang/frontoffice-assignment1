#include "leg.h"
#include <cmath>
/**
 * Implementacion de la clase 'FixedLeg' que representa los pagos fijos
 * Para calcular los flujos de caja se necesitan saber los periodos de pago, para calcular las fracciones de anyo
 * El interes esta acordado previamente y se supone que es en la duracion de los periodos de pago,
 * las clases superiores se ocuparan de calcularlo.
 */

//Clase FixedLeg
double FixedLeg::price() {

	//Obtenemos el numero de dias de un año de la calculadora instanciada
	int nDaysYear = dayCalculator.getNDaysYear();

	//Obtenmos el numero de dias total que dura la inversion
	double nDaysInvest = dayCalculator.compute_daycount(vPeriods.front(), vPeriods.back());

	//Calculamos las dcfs (Day count fraction)
	int i;
	std::vector<double> dcfs{};
	for(i = 1; i < vPeriods.size(); i++){
		double dcf = dayCalculator.compute_daycount(vPeriods.at(i - 1), vPeriods.at(i)) / (double)nDaysYear;
		dcfs.push_back(dcf);
	}

	//Calculamos los flujos de caja
	std::vector<double> aCashFlows{};
	for(i = 0; i < dcfs.size(); i++){
		dcfs.push_back(rate * dcfs.at(i) * notional);
	}

	//Calculamos la valoracion de la pata fija
	double res = 0.0;
	double rActInc = 0.0;
	for(i = 1; i < vPeriods.size(); i++){
		rActInc += dayCalculator.compute_daycount(vPeriods.at(i - 1), vPeriods.at(i)) / nDaysInvest;
		res += aCashFlows.at(i - 1) * std::exp(-(rate * rActInc));
	}
	return res;
}
