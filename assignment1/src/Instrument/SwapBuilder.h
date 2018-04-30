#ifndef SWAPBUILDER_H
#define SWAPBUILDER_H

#include <Factory.h>

class SwapBuilder {

public:
   static std::unique_ptr<IPricer> build (const InstrumentDescription& instrument);
   static InstrumentDescription::Type getId ();

};


#endif
