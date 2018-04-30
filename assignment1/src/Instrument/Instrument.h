#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include "../Leg/leg.h"
#include "../Leg/ZeroCurve/zerocurve.h"


class Instrument {

public:
    virtual double price() const = 0;

    Leg *theReceiver;
    ZeroRateCurve theZeroRateCurve;

    Instrument(Leg *receiver, ZeroRateCurve zeroRateCurve) : theReceiver{receiver}, theZeroRateCurve{zeroRateCurve} {}

};

class Bond : public Instrument {
public:

    double price();

    Bond(FixedLeg *Receiver, ZeroRateCurve zeroRateCurve) : Instrument(Receiver, zeroRateCurve) {}

};

class Swap : public Instrument {
public:

    Leg *thePayer;

    double price();

    Swap(Leg *Receiver, Leg *Payer, ZeroRateCurve zeroRateCurve) : Instrument(Receiver, zeroRateCurve) {
        thePayer = Payer;
    }
};

#endif
