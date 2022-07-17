#include <iostream>

using namespace std;

int factorial(const int);

int main()
{
    int n, result;
    cout<< "Please input n: ";
    cin >> n;

    result = factorial(n);
    cout << "n! is " << result << endl;
    return 0;
}

int factorial(const int n){
    if (n > 1)
        return n * factorial(n-1);
    return 1;
}