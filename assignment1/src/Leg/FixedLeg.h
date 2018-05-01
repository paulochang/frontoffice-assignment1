//
// Created by Paulo Chang on 5/1/18.
//

#ifndef SQF_FIXEDLEG_H
#define SQF_FIXEDLEG_H

#include "Leg.h"

//Clase que implementa una pata fijado
class FixedLeg : public Leg {

public:

    // Constructor (LLamamos al constructor de la superclase)
    FixedLeg(double notional, double rate, std::vector<boost::gregorian::date> referenceDates, DayCountCalculator &dayCalculator)
            :
            Leg(notional, rate, referenceDates, dayCalculator) {}

    //Metodo para calcular el precio en un pata fija
    double price() override;

    std::vector<double> getLegCashFlows(std::vector<double> dayCountFractionVector) override;
};

#endif //SQF_FIXEDLEG_H
