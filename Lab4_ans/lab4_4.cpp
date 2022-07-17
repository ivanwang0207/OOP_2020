#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(){
	int x, y;
	cout<< "Please input the two integer numbers that you want to find the GCD of: ";
	cin >> x >> y;

	cout << "The GCD of " << x << " and " << y << " is " << gcd(x, y) << endl;
	return 0;
}

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}