#include "DoubleArray.h"
#include "DoubleArrayID.h"
#include <iostream>

using namespace std;

int main(){
    DoubleArrayID dar0;
    DoubleArrayID dar1(3, 0.1);
    DoubleArrayID dar2(6, 0.5);
    DoubleArray* dar3 = new DoubleArrayID(dar1);
    DoubleArrayID dar4;
    dar4 = dar2;
    cout << dar0 << dar1 << dar2 << *dar3 << dar4;

    delete dar3;

    return 0;
}
