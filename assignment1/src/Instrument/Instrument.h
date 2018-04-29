#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <../Leg/leg.h>

struct InstrumentDescription {
	enum Type {bond, swap};
	Type type;
	InstrumentDescription(Type type_):type(type_){} 
	LegDescription payer;
	LegDescription receiver;
};

class Instrument {
	
	private:
		InstrumentDescription instrumentDescription;
		
	public:

		double operator()(InstrumentDescription& instrumentDescription) const;
		
		double price();

};

class Bond : public Instrument {
	public:

		Bond(InstrumentDescription& instrumentDescription) : Instrument(InstrumentDescription instrumentDescription) {};
		
	private:
		
		Leg fixedLeg();
		
};

class Swap : public Instrument {
	public:

		Bond(InstrumentDescription& instrumentDescription) : Instrument(InstrumentDescription instrumentDescription) {};

	private:

		Leg fixedLeg();
		
		Leg floatingLeg();

};


#endif
