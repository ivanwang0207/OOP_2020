#ifndef DOUBLE_ARRAYID_H
#define DOUBLE_ARRAYID_H
#include "DoubleArray.h"

class DoubleArrayID : public DoubleArray{
public:
    DoubleArrayID() = default;
    DoubleArrayID(unsigned in_size, double val = 0.0);
    DoubleArrayID(const DoubleArrayID& rhs);
    DoubleArrayID& operator=(const DoubleArrayID& rhs);
    void print(std::ostream&) const;
    ~DoubleArrayID();

protected:
    int* randID = nullptr;
};

#endif
