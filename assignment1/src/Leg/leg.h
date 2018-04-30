#ifndef LEG_H
#define LEG_H

#include <string>
#include <utility>
#include <vector>
#include "Btime/btime.h"
/**
 * Clase que representa una pata de un instrumento financiero.
 * Una pata de un instrumento financiero se considera una serie de peridos en un intervalo de tiempo concreto
 * Para calcular el precio de una pata hace falta el nocional o nominal principal, el interes fijado (en caso de
 * ser una pata flotante, se necesita una curva de interes, que implementa la subclase 'Floating Leg'), las fechas
 * de inicio y fin y el numero de subperiodos que consta el periodo principal (en esta practica se considera un año)
 * NOTA: El interes proporcionado se asume que es acorde al subperiodo concreto (si son dos subperiosos, el interes es semianual,
 * si son 3 subperiodos el interes es trimestarl, etc). Respecto a las fechas, estas deben ser ordenadas de menor a mayor y la primera
 * fecha se corresponde a la fecha de acuerdo del instrumento (bono o swap) y el resto son las fechas correspondientes al pago de flujos
 */


//Clase prinbcipal
class Leg {
protected:
    double notional;
    double rate;
    std::vector<std::string> vPeriods;
    DayCountCalculator *dayCalculator;
public:

    //Constructor
    Leg(double eNotional, double eRate, std::vector<std::string> eVPeriods, DayCountCalculator *eDayCalculator) :
            notional{eNotional}, rate{eRate}, vPeriods{std::move(eVPeriods)}, dayCalculator{eDayCalculator} {}

    //Destructor
    virtual ~Leg();

    //Metodo abstracto para calcular el precio de una pata
    virtual double price() = 0;
};

//Clase que implementa una pata fijado
class FixedLeg : public Leg {

public:

    // Constructor (LLamamos al constructor de la superclase)
    FixedLeg(double eNotional, double eRate, std::vector<std::string> eVPeriods, DayCountCalculator *eDayCalculator)
            :
            Leg(eNotional, eRate, std::move(eVPeriods), eDayCalculator) {}

    //Metodo para calcular el precio en un pata fija
    double price() override;
};

//Clase que implementa una pata flotante
class FloatingLeg : public Leg {

public:

    // Constructor (LLamamos al constructor de la superclase)
    FloatingLeg(double eNotional, double eRate, std::vector<std::string> eVPeriods,
                DayCountCalculator *eDayCalculator) :
            Leg(eNotional, eRate, std::move(eVPeriods), eDayCalculator) {}

    //Metodo para calcular el precio en un pata fija
    double price() override;
};

#endif
