#include "Instrument.h"


	




	//Bond(InstrumentDescription instrumentDescription) : Instrument(InstrumentDescription instrumentDescription) {
	//Bond::Bond(InstrumentDescription instrumentDescription) : Instrument(instrumentDescription) {
		
		//fixedLeg = instrumentDescription.receiver;
		//floatingLeg = NULL;
		
		//};
	
	
	double Bond::price(){
		
		return instrumentDescription.receiver.price();
		
	}
	
