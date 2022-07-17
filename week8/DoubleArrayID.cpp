#include "DoubleArrayID.h"
#include <iostream>
#include <ctime> // random seed
#include <cstdlib> //random pick
using namespace std;

DoubleArrayID::DoubleArrayID(unsigned in_size, double val) : DoubleArray(in_size, val){
    randID = new int[array_size];
    srand(time(0)); // random seed
    for (unsigned index = 0; index != array_size; ++index)
        randID[index] = rand()%100;
}

DoubleArrayID::DoubleArrayID(const DoubleArrayID& rhs) :
                                                       DoubleArray(rhs){
    randID = new int[array_size];
    for (unsigned index = 0; index != array_size; ++index)
        randID[index] = rhs.randID[index];
}

DoubleArrayID& DoubleArrayID::operator = (const DoubleArrayID& rhs){
    if (this == &rhs)
        return *this;
    DoubleArray::operator=(rhs); // copy base portion
    if (randID != nullptr)
        delete[] randID;
    randID = new int[array_size];
    for (unsigned index = 0; index != array_size; ++index)
        randID[index] = rhs.randID[index];
    return *this;
}

void DoubleArrayID::print(ostream& os) const {
    DoubleArray::print(os);
    os << ":: {";
    if(array_size > 0){
        for (unsigned index = 0; index < array_size - 1; ++index){
            os << randID[index] << ", ";
        }
        os << randID[array_size - 1] << "}" << endl;
    } else os << " }" << endl;
}

DoubleArrayID::~DoubleArrayID(){
    if (randID != nullptr){
        delete[] randID;
        cout << "\tdelete[] in subclass destructor" << endl;
    }
}
