#ifndef RFRACTION_H
#define RFRACTION_H
#include <iostream>
#include "Fraction.h"
class RFraction : public Fraction
{

	using Base = Fraction;

public:
	
	RFraction(const int n = 1, const int d = 1);

private:

	std::istream& input(std::istream& in) override;

	void reduce();
};

#endif // FRACTION_H