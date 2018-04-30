#include "zerocurve.h"
/**
 * Impelmentacion de la clase ZeroRateCurve
 */

//Instancia singleton
//std::unique_ptr<ZeroRateCurve> ZeroRateCurve::sZRCurve = nullptr;

//ZeroRateCurve - ZeroRateCurve
void ZeroRateCurve::loadZCMap() {
    mapZeroRates["01/01/2018"] = 0.05;
    mapZeroRates["01/07/2018"] = 0.058;
    mapZeroRates["01/01/2019"] = 0.064;
    mapZeroRates["01/07/2019"] = 0.05;
}

//getZRCurve - ZeroRateCurve (Singleton)
/*std::unique_ptr<ZeroRateCurve> ZeroRateCurve::getZRCurve() {
    if (sZRCurve == nullptr) {
        sZRCurve = std::unique_ptr<ZeroRateCurve>(new ZeroRateCurve());
    }
    return std::move(sZRCurve);
}*/

//getRateFromDateString - ZeroRateCurve
double ZeroRateCurve::getRateFromDateString(std::string &date) {
    if (mapZeroRates.find(date) != mapZeroRates.end()) {
        return mapZeroRates.at(date);
    }
    return -1.0;
}