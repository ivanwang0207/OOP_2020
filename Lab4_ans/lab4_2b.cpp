#include <iostream>

using namespace std;

int factorial(const int n);

int main()
{
	int n, result;
	cout<< "Please input n: ";
	cin >> n;

	//factorial(n, result);
	// or for (b):
	result = factorial(n);
	cout << "n! is " << result << endl;
	return 0;
}

void factorial(int n, int& result ){
	result = 1;
	for(int i = 1; i <= n; i++)
		result *= i;
}

int factorial(const int n){
	if(n > 1)
		return n*factorial(n-1);
	return 1;
}