/**
 * Implementacion de la clase base del Tir
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "Tir.h"
/*
*
* notional principal
* cashflows arreglos de flujos
* speriod = no. de subperíodos en un año    2 
* tPeriods = no. de años que dura un Bono_TIR       2... 4 pagos
* mPeriod = periodo principal                       3.. 
*/
/*
 double Bono_TIR::operator()(const double notional, const std::vector<double> &aCashFlows, const int sPeriods,
    const double tPPeriods, const int mPeriod) {

 //Calculamos el incremento d periodo (si es 1 o menor se toma el periodo principal)
 double pIncrement = (sPeriods <= 1) ? mPeriod : ((double)mPeriod / (double)sPeriods);
 /*
  * Calculamos el numero de subperiodos totales
  * Los periodos deben ser exactos, en caso contrario se emite error
  */
/*
  if(std::fmod(tPPeriods, pIncrement) != 0){
  std::cerr << "El numero de periodos debe ser proporcional al periodo total del bono: " << 
    tPPeriods << '\n';
  return -1.0;
 }
 int tSubperiods = (int)((sPeriods < 2) ? tPPeriods : (tPPeriods / pIncrement));
 //El numero de flujos de caja debe ser igual al numero de subperiodos
 if(aCashFlows.size() != (unsigned int)tSubperiods){
  std::cerr << "El numero de subperiodos o periodos debe ser igual al numero de flujos de caja: " << 
    aCashFlows.size() << " |= " <<  tSubperiods << '\n';
  return -1.0;
 }
 double antIRate = 0.0;
 double actIRate = 0.0;
 double bValue = 0.0;
 double derBValue = 0.0;
 int i = 0, j;
 //Asignamos el interes inicial
 actIRate = iRate; 
    //Iteramos hasta que el resultado sea menor que el error o bien se acaben las iteraciones
    while((std::abs(actIRate - antIRate) > error) && (i < nIterations)){
        i++;
        antIRate = actIRate;
        for(j = 0; j < tSubperiods; j++){
            double actInc = ((j + 1) * pIncrement);
      bValue += (aCashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * 
              std::exp(-(actIRate * actInc));
     }
     for(j = 0; j < tSubperiods; j++){
         double actInc = ((j + 1) * pIncrement);
      derBValue += (-actInc) * (aCashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * 
              std::exp(-(actIRate * actInc));
     }
     actIRate = actIRate - (bValue / derBValue);
    }
 return actIRate;
}
*/