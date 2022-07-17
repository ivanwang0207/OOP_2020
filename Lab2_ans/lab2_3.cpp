#include <iostream>
using namespace std;
int main(){
	int a, b;
	cout<< "Please input two integers:";
	
	cin >> a >> b;
	
	cout << "(a,b) = (";
	cout << a << "," << b << ")" <<endl;
	
	int* ptrA = &a;
	int* ptrB = &b;
	
	cout<< "Please input two new integers:";
	cin >> *ptrA >> *ptrB;
	
	cout << "(a,b,*ptrA,*ptrB) = (";
	cout << a << "," << b << "," << *ptrA << "," << *ptrB << ")" <<endl;
	cout << "end of assignment 3\n";
    return 0;
}