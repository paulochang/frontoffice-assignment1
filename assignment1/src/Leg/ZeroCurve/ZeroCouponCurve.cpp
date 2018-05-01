#include "ZeroCouponCurve.h"
/**
 * Impelmentacion de la clase ZeroRateCurve
 */

//Instancia singleton
//std::unique_ptr<ZeroCouponCurve> ZeroCouponCurve::sZRCurve = nullptr;

//ZeroCouponCurve - ZeroCouponCurve
void ZeroCouponCurve::loadDefaultZCMap() {
    m_mapZeroRates[boost::gregorian::from_string("03/10/2016")] = 0.0474;
    m_mapZeroRates[boost::gregorian::from_string("03/04/2017")] = 0.05;
    m_mapZeroRates[boost::gregorian::from_string("02/10/2017")] = 0.051;
    m_mapZeroRates[boost::gregorian::from_string("02/04/2018")] = 0.052;
}

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