#include "DoubleArray.h"
#include <iostream>
using namespace std;

DoubleArray::DoubleArray(unsigned in_size, double val) : array_size(in_size) {
    raw_data = new double[array_size];
    for (unsigned index = 0; index != array_size; ++index)
        raw_data[index] = val;
}

DoubleArray::DoubleArray(const DoubleArray& rhs) {
    array_size = rhs.array_size;
    raw_data = new double[array_size];
    for (unsigned index = 0; index != array_size; ++index)
        raw_data[index] = rhs.raw_data[index];
}

DoubleArray& DoubleArray::operator = (const DoubleArray& rhs) {
    if (this == &rhs)
        return *this;
    if (raw_data != nullptr)
        delete[] raw_data;
    array_size = rhs.array_size;
    raw_data = new double[array_size];
    for (unsigned index = 0; index != array_size; ++index)
        raw_data[index] = rhs.raw_data[index];
    return *this;
}

void DoubleArray::print(ostream& os) const {
    os << "array size: " << array_size << ", {";
    if(array_size > 0){
      for (unsigned index = 0; index < array_size - 1; ++index){
          os << raw_data[index] << ", ";
      }
      os << raw_data[array_size - 1] << "}" << endl;
    }
    else os << " }" <<  endl;
}

DoubleArray::~DoubleArray() {
    if (raw_data != nullptr){
        delete[] raw_data;
        std::cout << "delete[] in destructor!" << std::endl;
    }
}

ostream& operator << (ostream& os, const DoubleArray& a) {
    a.print(os);
    return os;
}
