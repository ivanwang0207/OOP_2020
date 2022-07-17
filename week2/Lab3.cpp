#include <string>
#include <iostream>  
using namespace std;  

int main(){

    int a;
    int b;
    int* ptrA;
    int* ptrB;

    cout << "plz input two integers: ";    
    cin >> a;
    cin >> b;

    cout << "(a,b) = (" << a << "," << b << ")" << endl;

    cout << "plz input two new integers: ";   
    ptrA = &a;
    ptrB = &b; 
    cin >> *ptrA;
    cin >> *ptrB;

    cout << "(a,b,ptrA,ptrB) = ("  << a << "," << b << "," <<  *ptrA << "," << *ptrB << ")" << endl;

    return 0;
}