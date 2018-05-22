#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <utility>
#include "Leg/Leg.h"


class Instrument {

public:
    virtual double price() const = 0;

    Leg *theReceiver;

    Instrument(Leg *receiver) : theReceiver{receiver} {}

};
#endif
