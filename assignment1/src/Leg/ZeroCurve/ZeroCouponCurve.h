#ifndef ZERO_CURVE_H
#define ZERO_CURVE_H

#include <string>
#include <map>
#include <memory>
#include <utility>
#include <boost/date_time/gregorian/gregorian.hpp>

/**
 * Clase que implemenbta una curva de intereses a cupones cero.
 * En este caso, para dart sencillez a la practica solo usaremos unos valores estaticos
 * que aparecen en el ejemplo del tema2.
 */

class ZeroCouponCurve {
private:

    //Mapa que contiene los tipos de interes agrupados por fecha
    std::map<boost::gregorian::date, double> mapZeroRates{};

    //Carga el mapa de valores
    void loadDefaultZCMap();

public:

    ZeroCouponCurve() {
        loadDefaultZCMap();
    }

    explicit ZeroCouponCurve(std::map<boost::gregorian::date, double> ratesMap) {
        mapZeroRates = std::move(ratesMap);
    }
    //Obtiene la instancia singleton
    //static std::unique_ptr<ZeroCouponCurve> getZRCurve();

    //Obtiene un tipo de interes a partir de la fecha
    double getRateFromDateString(std::string &date) const;

    double getRateFromDateString(boost::gregorian::date &date) const;
};

#endif