//
// Created by Paulo Chang on 5/1/18.
//

#ifndef SQF_SWAP_H
#define SQF_SWAP_H

#include "Instrument.h"
class Swap : public Instrument {
public:

    Leg *thePayer;

    double price();

    Swap(Leg *Receiver, Leg *Payer, ZeroCouponCurve zeroRateCurve) : Instrument(Receiver, std::move(zeroRateCurve)) {
        thePayer = Payer;
    }
};


#endif //SQF_SWAP_H
