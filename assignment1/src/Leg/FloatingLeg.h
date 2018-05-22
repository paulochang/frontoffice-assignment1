//
// Created by Paulo Chang on 5/1/18.
//

#ifndef SQF_FLOATINGLEG_H
#define SQF_FLOATINGLEG_H

#include <Leg/ZeroCurve/ZeroCouponCurve.h>
#include "Leg.h"

//Clase que implementa una pata flotante
class FloatingLeg : public Leg {

    ZeroCouponCurve m_index;
public:

    // Constructor (LLamamos al constructor de la superclase)
    FloatingLeg(double notional, double rates, std::vector<boost::gregorian::date> referenceDates,
                DayCountCalculator &dayCalculator, ZeroCouponCurve &zeroCouponCurve,  ZeroCouponCurve index) :
            Leg(notional, rates, std::move(referenceDates), dayCalculator, zeroCouponCurve) {
        m_index = index;
    }

    //Metodo para calcular el precio en un pata fija
    double price() override;

    std::vector<double> getLegCashFlows(std::vector<double> dayCountFractionVector) override;

};

#endif //SQF_FLOATINGLEG_H
