#include "Instrument.h"

class Instrument {
	
	private:
		std:string type;
		
	public:

		double operator()(const std::string& start_period, const std::string& end_period, std:string type) const;

};

class Bond : public Instrument {
	public:

		Bond(const std::string& start_period, const std::string& end_period) : Instrument(start_period, end_period, "bond") {};
		
	private:
		
		Leg fixedLeg();
		
};

class Swap : public Instrument {
	public:

		Bond(const std::string& start_period, const std::string& end_period) : Instrument(start_period, end_period, "swap") {};

	private:

		Leg fixedLeg();
		
		Leg floatingLeg();

};


#endif 