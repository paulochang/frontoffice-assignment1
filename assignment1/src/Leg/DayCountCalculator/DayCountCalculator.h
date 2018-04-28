#ifndef DAYTIMECALCULATOR_H
#define DAYTIMECALCULATOR_H

#include <string>

 
const int N_DAYS_ACTUAL_360 = 360;
const int N_DAYS_THIRTY_360 = 360;

class DayCountCalculator {
	private:
		int nDaysYear;
	public:
		
		DayCountCalculator(int eNDaysYear) : nDaysYear{eNDaysYear} {}

		double compute_daycount(const std::string& from, const std::string& to) const;

		int getNDaysYear();

		double operator()(const std::string& start, const std::string& end_period) const;

};

class Actual_360 : public DayCountCalculator {
	public:

		Actual_360() : DayCountCalculator(N_DAYS_ACTUAL_360) {};
		
};

class Thirty_360 : public DayCountCalculator {
	public:

		Thirty_360() : DayCountCalculator(N_DAYS_THIRTY_360) {}

	private:

		double compute_daycount(const short years, const short months, const short days_from, const short days_to);
};

#endif