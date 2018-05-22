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

    boost::gregorian::date m_startDate;
    //Mapa que contiene los tipos de interes agrupados por fecha
    std::map<boost::gregorian::date, double> m_mapZeroRates{};

public:

    ZeroCouponCurve() {
        m_mapZeroRates[boost::gregorian::from_string("2016-10-03")] = 0.0474;
        m_mapZeroRates[boost::gregorian::from_string("2017-04-03")] = 0.05;
        m_mapZeroRates[boost::gregorian::from_string("2017-10-02")] = 0.051;
        m_mapZeroRates[boost::gregorian::from_string("2018-04-02")] = 0.052;
    }

    explicit ZeroCouponCurve(std::map<boost::gregorian::date, double> ratesMap) {
        m_mapZeroRates = std::move(ratesMap);

    }
    //Obtiene la instancia singleton
    //static std::unique_ptr<ZeroCouponCurve> getZRCurve();

    //Obtiene un tipo de interes a partir de la fech

    double getRateFromDateString(boost::gregorian::date date) const;

    double getRateFromDateString(std::string &date) const;

};

#endif