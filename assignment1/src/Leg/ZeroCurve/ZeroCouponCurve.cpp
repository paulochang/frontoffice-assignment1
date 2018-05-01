#include "ZeroCouponCurve.h"
/**
 * Impelmentacion de la clase ZeroRateCurve
 */

//Instancia singleton
//std::unique_ptr<ZeroCouponCurve> ZeroCouponCurve::sZRCurve = nullptr;

//ZeroCouponCurve - ZeroCouponCurve
void ZeroCouponCurve::loadDefaultZCMap() {
    mapZeroRates[boost::gregorian::from_string("03/10/2016")] = 0.0474;
    mapZeroRates[boost::gregorian::from_string("03/04/2017")] = 0.05;
    mapZeroRates[boost::gregorian::from_string("02/10/2017")] = 0.051;
    mapZeroRates[boost::gregorian::from_string("02/04/2018")] = 0.052;
}

//getRateFromDateString - ZeroCouponCurve
double ZeroCouponCurve::getRateFromDateString(std::string &date) const {
    if (mapZeroRates.find(boost::gregorian::from_string(date)) != mapZeroRates.end()) {
        return mapZeroRates.at(boost::gregorian::from_string(date));
    }
    return NAN;
}

double ZeroCouponCurve::getRateFromDateString(boost::gregorian::date &date) const {
    if (mapZeroRates.find(date) != mapZeroRates.end()) {
        return mapZeroRates.at(date);
    }
    return NAN;
}