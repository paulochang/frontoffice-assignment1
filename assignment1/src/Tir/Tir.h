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
/*
class Bono_TIR {
 private:
  int nMinIterations{100000000};
  int nIterations{nMinIterations};
  double error{1.0e-15};
  double iRate{6.0};
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
*/

#include <boost/math/tools/roots.hpp>
//namespace boost { namespace math {
//namespace tools {

class Bono_TIR{
	
	
public:
	
	/*
	static double notional;
	static std::vector<double> &aCashFlows;
	static int sPeriods;
	static double tPPeriods;
	static int mPeriod;
	*/
	
  //static double notional;// = 100;
	//static std::vector<double> CashFlows;// = {2.99, 2.98, 2.97, 101.60};
	//static int sPeriods;// = 2;
  //static double tPPeriods;// = 2.0;
	//static int mPeriod;// = 1;

	
	/*
  double operator()(const double notional_p, const std::vector<double> &aCashFlows_p, const int sPeriods_p, const double tPPeriods_p, const int mPeriod_p){
		notional = notional_p;
		aCashFlows = aCashFlows_p;
		sPeriods = sPeriods_p;
		tPPeriods = tPPeriods_p;
		mPeriod = mPeriod_p;
  };
	*/
	
	/*
	Bono_TIR(const double notional_p, const std::vector<double> &aCashFlows_p, const int sPeriods_p, const double tPPeriods_p, const int mPeriod_p){
		notional = notional_p;
		aCashFlows = aCashFlows_p;
		sPeriods = sPeriods_p;
		tPPeriods = tPPeriods_p;
		mPeriod = mPeriod_p;
	};
	*/
	
	
	static double value (double tSubperiods, double pIncrement, double actIRate, std::vector<double> CashFlows){
		int i = 0, j;
		
		double bValue = 0.0;
		double notional = 100;
		for(j = 0; j < tSubperiods; j++){
			double actInc = ((j + 1) * pIncrement);
			//bValue += (aCashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * std::exp(-(actIRate * actInc));
			bValue += (CashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * std::exp(-(actIRate * actInc));
		}
		return bValue;
	}
	
	static double der_value(double tSubperiods, double pIncrement, double actIRate, std::vector<double> CashFlows){
		int i = 0, j;
		double notional = 100;
		double derBValue = 0.0;
		for(j = 0; j < tSubperiods; j++){
			double actInc = ((j + 1) * pIncrement);
			//derBValue += (-actInc) * (aCashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * std::exp(-(actIRate * actInc));
			derBValue += (-actInc) * (CashFlows.at(j) + ((j == (tSubperiods - 1)) ? notional : 0)) * std::exp(-(actIRate * actInc));
		}
		return derBValue;
	}
	
	template <class T>
	struct cbrt_functor
	{
	   cbrt_functor(T const& target) : a(target){}
	   std::tuple<T, T> operator()(T const& z)
	   {
	      //T sqr = z * z;
	      //return std::make_tuple(sqr * z - a, 3 * sqr);
			 return std::make_tuple(value(4, 0.5, z, {5.0, 5.8, 6.4, 6.8}), der_value(4, 0.5, z, {5.0, 5.8, 6.4, 6.8}));
	   }
	private:
	   T a;
	};
	
public:
	template <class T>
	T cbrt(T z)
	{
	   using namespace std;
	   int exp;
	   frexp(z, &exp);
	   T min = 0;//ldexp(0.5, exp/3);
	   T max = 10;//ldexp(2.0, exp/3);
	   T guess = z;//ldexp(1.0, exp/3);
	   int digits = std::numeric_limits<T>::digits;
	   return boost::math::tools::newton_raphson_iterate(cbrt_functor<T>(z), guess, min, max, digits);
	}

};
//}}}




