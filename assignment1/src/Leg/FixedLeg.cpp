#include "FixedLeg.h"

/**
 * Implementacion de la clase 'FixedLeg' que representa los pagos fijos
 * Para calcular los flujos de caja se necesitan saber los periodos de pago, para calcular las fracciones de año
 * El interes esta acordado previamente y se supone que es en la duracion de los periodos de pago,
 * las clases superiores se ocuparan de calcularlo.
 */


std::vector<double> FixedLeg::getLegCashFlows(std::vector<double> dayCountFractionVector){
    std::vector<double> legCashFlows{};
    for (auto currentFraction : dayCountFractionVector)
        legCashFlows.emplace_back(m_rate * currentFraction * m_notional);
    return legCashFlows;
}

//Clase FixedLeg
double FixedLeg::price() {

    //Generate day count fraction vector
    std::vector<double> dayCountFractionVector{getDayCountFractionVector()};

    //Calculate the legCashFlows
    std::vector<double> legCashFlows{getLegCashFlows(dayCountFractionVector)};

    //
    std::vector<double> legDiscountFactors(getDiscountFactors(dayCountFractionVector));
    
    double totalDiscountedValue = 0.0;
    double currentPeriodFraction = 0.0;

    for (int i = 0; i < dayCountFractionVector.size(); ++i) {
        currentPeriodFraction += dayCountFractionVector.at(i);
        totalDiscountedValue += continuous_discount(legCashFlows.at(i), legDiscountFactors.at(i), currentPeriodFraction);
    }

    /*//Calculamos la valoracion de la pata fija
    double res = 0.0;
    double rActInc = 0.0;
    for (int i = 1; i < m_payingDates.size(); i++) {
        rActInc += dayCountFractionVector.at(i-1);
        res += legCashFlows.at(i - 1) * std::exp(-(m_rate * rActInc));
    }*/
    return totalDiscountedValue;
}
