#include "Fraction.h"
#include "RFraction.h"
#include <iostream>
using namespace std;

int main() {
	Fraction f1(2, 4);
	Fraction f2;
	cout << "Enter a fraction: ";
	cin >> f2;
	cout << "Fractions are: ";
	cout << f1 << ", ";
	cout << f2 << endl;

	RFraction rf1(2, 4);
	RFraction rf2;
	cout << "Enter a fraction to be reduced: ";
	cin >> rf2;
	cout << "Reduced fractions are: ";
	cout << rf1 << ", ";
	cout << rf2 << endl;
	
	Fraction* rfp1 = new RFraction(-6, 16);
	Fraction* rfp2 = new RFraction();
	cout << "Enter a fraction to be reduced: ";
	cin >> *rfp2;
	cout << "Reduced fractions are: ";
	cout << *rfp1 << ", ";
	cout << *rfp2 << endl;
	delete rfp1;
	delete rfp2;
}
