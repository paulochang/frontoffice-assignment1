#ifndef ZERO_CURVE_H
#define ZERO_CURVE_H

#include <string>
#include <map>
#include <memory>
#include <utility>

/**
 * Clase que implemenbta una curva de intereses a cupones cero.
 * En este caso, para dart sencillez a la practica solo usaremos unos valores estaticos
 * que aparecen en el ejemplo del tema2.
 */

class ZeroRateCurve {
private:

    //Mapa que contiene los tipos de interes agrupados por fecha
    std::map<std::string, double> mapZeroRates{};

    //Instancia singleton
    //static std::unique_ptr<ZeroRateCurve> sZRCurve;

    //Constructor privado


    //Carga el mapa de valores
    void loadZCMap();

public:

    ZeroRateCurve() {
        loadZCMap();
    }

    ZeroRateCurve(std::map<std::string, double> ratesMap) {
        mapZeroRates = ratesMap;
    }
    //Obtiene la instancia singleton
    //static std::unique_ptr<ZeroRateCurve> getZRCurve();

    //Obtiene un tipo de interes a partir de la fecha
    double getRateFromDateString(std::string &date);
};

#endif