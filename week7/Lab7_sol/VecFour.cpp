#include "VecFour.h"
#include <cmath>

using namespace std;

VecFour::VecFour(const double& x, const double& y, const double& z, const double& h)
	:a(x), b(y), c(z), d(h){}

/*
VecFour& VecFour::operator*=(const VecFour& rhs){
	a*=rhs.a;
	b*=rhs.b;
	c*=rhs.c;
	d*=rhs.d;

	return *this;
}
*/

VecFour& VecFour::operator*=(const double& rhs){
	a*=rhs;
	b*=rhs;
	c*=rhs;
	d*=rhs;

	return *this;
}

const double VecFour::length() const {
	//return sqrt(a+b+c+d);
	return sqrt(a*a + b*b + c*c + d*d);
}
