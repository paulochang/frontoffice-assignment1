#include "ZeroCouponCurve.h"
/**
 * Impelmentacion de la clase ZeroRateCurve
 */

//Instancia singleton
//std::unique_ptr<ZeroCouponCurve> ZeroCouponCurve::sZRCurve = nullptr;


double ZeroCouponCurve::getRateFromDateString(boost::gregorian::date date) const {
    if (m_mapZeroRates.find(date) != m_mapZeroRates.end()) {
        return m_mapZeroRates.at(date);
    }
    return NAN;
}

//getRateFromDateString - ZeroCouponCurve
double ZeroCouponCurve::getRateFromDateString(std::string &date) const {
    return getRateFromDateString(boost::gregorian::from_string(date));
}