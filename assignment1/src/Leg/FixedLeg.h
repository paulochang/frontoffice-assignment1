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
    FixedLeg(double notional, double rate, std::vector<boost::gregorian::date> referenceDates,
             DayCountCalculator &dayCalculator, ZeroCouponCurve &zeroCouponCurve)
            :
            Leg(notional, rate, referenceDates, dayCalculator, zeroCouponCurve) {}

    //Metodo para calcular el precio en un pata fija
    double price() override;

    std::vector<double> getLegCashFlows(std::vector<double> dayCountFractionVector) override;

    double estimate_price(double x) override;
};

#endif //SQF_FIXEDLEG_H
