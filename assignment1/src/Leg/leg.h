#ifndef LEG_H
#define LEG_H

#include <string>
#include <vector>
#include "DayCountCalculator/DayCountCalculator.h"


class Leg {
	protected:
		double notional;
		double rate;
		std::vector<std::string> vPeriods;
		std::string legType;
		DayCountCalculator dayCalculator;
	
	public:
		
		Leg() = default;

		Leg(double eNotional, double eRate, std::vector<std::string> eVPeriods, DayCountCalculator eDayCalculator) : 
			notional{eNotional}, rate{eRate}, vPeriods{eVPeriods}, dayCalculator{eDayCalculator} {}

		//Destructor
		//virtual ~Leg();

		//Metodo abstracto para calcular el precio de una pata
		virtual double price() = 0;
 };
 
//Clase que implementa una pata fijado
class FixedLeg : public Leg {
	
	 
	 	// Constructor (LLamamos al constructor de la superclase)
		FixedLeg(double eNotional, double eRate, std::vector<std::string> eVPeriods, DayCountCalculator eDayCalculator) : 
				Leg(eNotional, eRate, eVPeriods, eDayCalculator){}

		

	public:
				FixedLeg() = default;
				
				//Metodo para calcular el precio en un pata fija
				double price();

};

//Clase que implementa una pata flotante
class FloatingLeg : public Leg {
	 
	 	// Constructor (LLamamos al constructor de la superclase)
		FloatingLeg(double eNotional, double eRate, std::vector<std::string> eVPeriods, DayCountCalculator eDayCalculator) : 
				Leg(eNotional, eRate, eVPeriods, eDayCalculator)
		{}

		
		
	public:
		FloatingLeg() = default;
		
		//Metodo para calcular el precio en un pata fija
		double price();
};

#endif	
