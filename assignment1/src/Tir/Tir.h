/**
 * Clase para calcular la Tir de un bono. Implementa el metodo de Newton Rapshon iterativo
 * para calcular la Tir
 * Los parametros que recibe esta clase son los siguoentes:
 *  -Nocional o nominal del bono
 *  -Array que contiene los valores de los cupones en el periodo o subperiodos concretos.
 *  La ultima psoicion se corresponde con el cupon final (Nominal + CF)
 *  -Numero de subperiodos que consta el periodo principal (si es 0 se toma el perioso principal)
 *  -Numero de`periodos totales que consta el bono (normalmente se hace en base a años, puede ser
 *  decimal, por ejemplo: 1,5 equivaldria a un año y medio)
 *  -Valor del periodo principal (normalmente es anual (1), pero puede ser mas)
 * Algunas restricciones puede ser que el numero de periodos sobre el periodo principal
 * tiene que ser igual o mayor a este mismo y que el numero de subperiodos o periodos (si no se utilizan)
 * tiene que coincidir con la longitud del array de flujos en caja.
 * El numero de iteraciones minimo y maximo por defecto es 100, pero puede ajustarse a mas.
 * Tambien puede ajustarse el error al evaluar para el metodo de newton Rapshon asi como el valor inicial
 */
class Bono_TIR {
 private:
  int nMinIterations{100};
  int nIterations{nMinIterations};
  double error{1.0e-11};
  double iRate{1.0};
 public:
  void setRate(double r) {
   iRate = r;
  }
  void setIterations(int iterations) {
   if(iterations >= nMinIterations){
    nIterations = iterations;
   }
  }
  void setError(double e) {

   //Solo tenemos en cuenta los errores pequeños
   if(e < error){
    error = e;
   }
  }
  double operator()(const double notional, const std::vector<double> &aCashFlows, const int sPeriods,
     const double tPPeriods, const int mPeriod);
		 
  double operator()(const double notional, const double *aCashFlows, const int sPeriods,
    const double tPPeriods, const int mPeriod = 1);
 };