#ifndef VEC_FOUR_H
#define VEC_FOUR_H

#include <iostream>

class VecFour {
    friend std::ostream& operator<<(std::ostream& ostr, const VecFour& input);
    friend std::ostream& operator<<(std::ostream& ostr, const VecFour& input);
    friend std::istream& operator>>(std::istream& istr, VecFour& input);
    friend VecFour& operator*=(VecFour&  lhs, const VecFour& rhs);
private:
	double a;
	double b;
	double c;
	double d;

public:
	VecFour(const double& x = 0, const double& y = 0, const double& z = 0, const double& h = 0);
	VecFour& operator=(const VecFour& rhs) = default;
	//VecFour& operator*=(const VecFour& rhs);
	VecFour& operator*=(const double& rhs);

	const double length() const;
	
	const bool operator<(const VecFour& rhs) const{
	//const bool operator<(const VecFour& rhs) {
	// you can define this one for set to use, or define the global function
	// which is at the end of this file
	    return this->length() < rhs.length();
	}

};

inline std::ostream& operator<<(std::ostream& ostr, const VecFour& input){
	ostr << '(' << input.a << ", " << input.b << ", " << input.c << ", " << input.d << ")";
	return ostr;
}

inline std::istream& operator>>(std::istream& istr, VecFour& input){
	istr >> input.a >> input.b >> input.c >> input.d;
	return istr;
}

inline const VecFour operator*(const double& lhs, const VecFour& rhs){
	auto ret = rhs;
	return ret *= lhs;
}

inline VecFour& operator*=(VecFour&  lhs, const VecFour& rhs){
	lhs.a *= rhs.a;
	lhs.b *= rhs.b;
	lhs.c *= rhs.c;
    lhs.d *= rhs.d;
	return lhs;
}

/*
// this is the alternative of the < definition using a global function
// the other is the one in the class definition of class VecFour;
inline const bool operator<(const VecFour& lhs, const VecFour& rhs){
//const bool operator<(const VecFour& lhs, const VecFour& rhs){
	return lhs.length() < rhs.length();
}
*/



#endif // VEC_FOUR_H
