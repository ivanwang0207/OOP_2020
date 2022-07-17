#ifndef RANDOMARRAY_H
#define RANDOMARRAY_H

#include <ctime>
class RandomArray
{
private:
    int n=5;
    int* ir;    
    static time_t seed_time;

public:
    RandomArray(){}
    RandomArray(int n):n(n){}

    static void setSeed();
    void loadArray();
    void printArray();
    void freeArray();
};

#endif