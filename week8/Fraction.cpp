#include "Fraction.h"

Fraction::Fraction(int n, int d)
	:numer(n), denom(d)
{

}

std::istream & Fraction::input(std::istream & in)
{
	// TODO: insert return statement here
	char tmp;
	in >> numer >> tmp >> denom;
	return in;

}

std::ostream& operator << (std::ostream& out, const Fraction& f) {
	out << f.numer << '/' << f.denom;
	return out;
}

std::istream & operator >> (std::istream & in, Fraction & f)
{
	// TODO: insert return statement here
	return f.input(in);	
}
