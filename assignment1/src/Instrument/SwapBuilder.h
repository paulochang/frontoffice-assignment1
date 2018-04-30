#ifndef SWAPBUILDER_H
#define SWAPBUILDER_H

#include <Factory.h>
#include <Instrument.h>

class SwapBuilder {

public:
   static std::unique_ptr<Instrument> build (const InstrumentDescription& instrument);
   static InstrumentDescription::Type getId ();

};


#endif
