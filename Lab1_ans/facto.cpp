#include <iostream>

using namespace std;

/* This is a nice recursive solution */
int factorial(int n){
    if(n < 0) return -1;
    if(n == 0 || n == 1) return 1;

    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "Please input the n number: ";
    cin >> n;
    cout << "The factorial of " << n << " is: " << factorial(n) << endl;
}
