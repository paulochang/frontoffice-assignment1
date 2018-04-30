#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include "../Leg/leg.h"

struct InstrumentDescription {
	enum Type {bond, swap};
	Type type;
	//InstrumentDescription(Type type_):type(type_){} 
	InstrumentDescription(){};
	FixedLeg payer;
	FloatingLeg receiver;
};

class Instrument {
	

	public:

		InstrumentDescription instrumentDescription;

		Instrument() = default;
		
		FixedLeg fixedLeg;
		FloatingLeg floatingLeg;

		//Instrument operator()(InstrumentDescription instrumentDescription) const;
		
		Instrument(InstrumentDescription instrumentDescription){};
		
		double price();

};

class Bond : public Instrument {
	public:

		Bond(InstrumentDescription instrumentDescription) : Instrument(instrumentDescription){
		
			instrumentDescription = instrumentDescription;
		
		};
		
		double price();
		
};

class Swap : public Instrument {
	public:

		Swap(InstrumentDescription instrumentDescription) : Instrument(instrumentDescription) {};

		double price();

};


#endif
