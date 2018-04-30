#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include "../Leg/leg.h"
#include <SwapBuilder.h>

namespace register_swap {
	
	FactoryRegistrator<SwapBuilder> registration;

}

InstrumentDescription::Type SwapBuilder::getId () {
	
	return InstrumentDescription::Type::swap; 
}

std::unique_ptr<IPricer> SwapBuilder::build (const InstrumentDescription& instrument) {
	
	std::unique_ptr<IPricer> swap;
  swap = std::make_unique<Swap>(receiver, payer, zerocouponCurve);

	return swap;

}


#endif
