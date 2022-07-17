#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H
#include <iostream>

class DoubleArray {
public:
    DoubleArray() = default;
    DoubleArray(unsigned in_size, double val = 0.0);
    DoubleArray(const DoubleArray& rhs);
    DoubleArray& operator=(const DoubleArray& rhs);
    virtual void print(std::ostream&) const;
    virtual ~DoubleArray();

protected:
    double* raw_data = nullptr;
    unsigned array_size = 0;
};

std::ostream& operator << (std::ostream&, const DoubleArray&);

#endif
