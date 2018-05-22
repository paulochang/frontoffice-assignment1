#include <boost/math/tools/roots.hpp>
#include "Leg/FixedLeg.h"
#include <Leg/ZeroCurve/ZeroCouponCurve.h>
#include <boost/bind.hpp>
#include "Btime/DayCountCalculator.h"
#include "Instrument/Instrument.h"

class Tir{

	Instrument myBond;
	FixedLeg myLeg;

	/*
	double notional = 100;
	double rate = 5.0/100;
	std::vector<boost::gregorian::date> referenceDates {};
	Actual_360 actualCalc = Actual_360();
	ZeroCouponCurve zeroCouponCurve {};
	*/

public:

	/*
	Tir(Instrument p_bond, double p_notional, double p_rate, std::vector<boost::gregorian::date> p_referenceDates, Actual_360 p_actualCalc){

		bond = p_bond;
		notional = p_notional;
		rate = p_rate;
		referenceDates = p_referenceDates;
		actualCalc = p_actualCalc;

	}
	*/

	Tir (Instrument bond, FixedLeg fixed_leg){

		myBond = bond;
		myLeg = fixed_leg;

	}

	/*
	bracket_and_solve_root(
	      F f,
	      const T& guess,
	      const T& factor,
	      bool rising,
	      Tol tol,
	      boost::uintmax_t& max_iter);
	*/

	template <class T>
	struct tir_functor {

	  tir_functor(T const& to_find_tir_of) : a(to_find_tir_of){}
	  T operator()(T const& x)
	  {
			T fx = myLEg.estimate_price(x) - myBond.price();
	    return fx;
	  }
	private:
	  T a;
	};

	double Get_Tir(double guess, double factor){

		FixedLeg myLeg {notional, rate, referenceDates, actualCalc, zeroCouponCurve};

		// Max iterations
		const boost::uintmax_t maxit = 10000;
		boost::uintmax_t it = maxit;

		// Improving result
		bool is_rising = true;

		// Epsilon tolerance
		int digits = std::numeric_limits<double>::digits;
		int get_digits = digits - 3;
		boost::math::tools::eps_tolerance<double> tol(get_digits);

		// Get roots
		std::pair<double, double> r = bracket_and_solve_root(tir_functor<double>(guess), guess, factor, is_rising, tol, it);

		// Midway between brackets
		return r.first + (r.second - r.first)/2;


	}

};
