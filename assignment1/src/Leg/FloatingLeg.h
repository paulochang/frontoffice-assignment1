//
// Created by Paulo Chang on 5/1/18.
//

#ifndef SQF_FLOATINGLEG_H
#define SQF_FLOATINGLEG_H

#include "Leg.h"

//Clase que implementa una pata flotante
class FloatingLeg : public Leg {

public:

    // Constructor (LLamamos al constructor de la superclase)
    FloatingLeg(double notional, double rates, std::vector<boost::gregorian::date> referenceDates,
                DayCountCalculator &dayCalculator) :
            Leg(notional, rates, std::move(referenceDates), dayCalculator) {}

    //Metodo para calcular el precio en un pata fija
    double price() override;

    std::vector<double> getLegCashFlows(std::vector<double> dayCountFractionVector) override;

};

#endif //SQF_FLOATINGLEG_H
