#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction {
	friend std::ostream& operator << (std::ostream& out, const Fraction& f);
	friend std::istream& operator >> (std::istream& in, Fraction& f);
public:
	
	Fraction(const int n = 1, const int d = 1);

protected:

	virtual std::istream& input(std::istream& in);

protected:
	int numer = 1;
	int denom = 1;
};

std::ostream& operator << (std::ostream& out, const Fraction& f);

std::istream& operator >> (std::istream& in, Fraction& f);

#endif // FRACTION_H