#include <iostream>
#include "RandomArray.h"

int main()
{
    RandomArray ra(3);
    RandomArray::setSeed();

    std::cout << "Using array 1: \n";
    for (int i=0; i<5; i++)
    {
        ra.loadArray();
        ra.printArray();
        ra.freeArray();
    }

    RandomArray ra2;
    ra2.loadArray();
    std::cout << "Array2: \n";
    ra2.printArray();
    ra2.freeArray();
    return 0;
}