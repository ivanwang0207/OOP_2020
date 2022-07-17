#include "RFraction.h"
#include <cmath>
RFraction::RFraction(int n, int d)
	:Fraction(n, d)
{
	reduce();
}

std::istream & RFraction::input(std::istream & in)
{
	// TODO: insert return statement here
	char tmp;
	in >> numer >> tmp >> denom;
	reduce();
	return in;

}

void RFraction::reduce()
{
	int n1 = std::abs(Fraction::numer);
	int n2 = std::abs(Fraction::denom);
	
	while (n1 != n2)
	{
		if (n1 > n2)
		{
			n1 -= n2;
		}
		else
			n2 -= n1;
	}
	

	Fraction::numer /= n1;
	Fraction::denom /= n1;
}