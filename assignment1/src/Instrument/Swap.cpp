#include "Instrument.h"


	
	double Swap::price(){
		
		return receiver.price() - payer.price();
		
	}
