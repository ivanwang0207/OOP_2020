#include <iostream>

using namespace std;

void factorial(int, int&);

int main()
{
    int n, result;
    cout<< "Please input n: ";
    cin >> n;

    factorial(n, result);
    cout << "n! is " << result << endl;
    return 0;
}

void factorial(int n, int& result ){
    result = 1;
    for (int i=1; i!=n+1; ++i){
        result *= i;
    }
}