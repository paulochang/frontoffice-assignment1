#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include "../Leg/leg.h"
#include "../Leg/ZeroCurve/zerocurve.h"


class Instrument {

	public:

		ZeroRateCurve zeroRateCurve;
		FixedLeg receiver;
		FloatingLeg payer;
		
		double price();
		
		Instrument(Leg receiver, Leg payer, ZeroRateCurve zerocouponCurve){
			
			//this->receiver = std::move(receiver);
			//this->payer = std::move(payer);
			//this->zeroRateCurve = std::move(zerocouponCurve);
			
			receiver = receiver;
			payer = payer;
			zeroRateCurve = zerocouponCurve;

		}

};

class Bond : public Instrument {
	public:
		
		double price();
		
};

class Swap : public Instrument {
	public:

		double price();

};

#endif
