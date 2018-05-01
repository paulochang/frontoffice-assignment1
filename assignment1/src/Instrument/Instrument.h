#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <utility>
#include "Leg/Leg.h"
#include "Leg/ZeroCurve/ZeroCouponCurve.h"


class Instrument {

public:
    virtual double price() const = 0;

    Leg *theReceiver;
    ZeroCouponCurve theZeroRateCurve;

    Instrument(Leg *receiver, ZeroCouponCurve zeroRateCurve) : theReceiver{receiver}, theZeroRateCurve{
            std::move(zeroRateCurve)} {}

};
#endif
