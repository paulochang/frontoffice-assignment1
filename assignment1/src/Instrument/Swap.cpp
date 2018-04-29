#include "Instrument.h"


	


	//Swap(InstrumentDescription& instrumentDescription) : Instrument(InstrumentDescription instrumentDescription) {
	//Swap(InstrumentDescription instrumentDescription) : Instrument(instrumentDescription) {
		
		//fixedLeg = instrumentDescription.receiver;
		//floatingLeg = instrumentDescription.payer;
		



	
	double Swap::price(){
		
		return instrumentDescription.receiver.price();
		
	}
