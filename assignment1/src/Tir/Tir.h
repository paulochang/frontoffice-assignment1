

#include <boost/math/tools/roots.hpp>
#include <boost/math/tools/numerical_differentiation.hpp>

//namespace boost { namespace math {
//namespace tools {

class Bono_TIR{


public:

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
			 return std::make_tuple(value(4, 0.5, z, {5.0, 5.8, 6.4, 6.8}), finite_difference_derivative(value, 4, 0.5, z, {5.0, 5.8, 6.4, 6.8}));
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
