#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RandomArray.h"

time_t RandomArray::seed_time = time(0); 

void RandomArray::setSeed()
{
    srand(seed_time);
}
void RandomArray::loadArray()
{
    ir = new int[n];  //"this" pointer set to the address of the object, can be omitted
    for (int i=0; i!= n; i++)
        ir[i] = rand()%1000;
}
void RandomArray::printArray()
{
    for (int i=0; i!= n; i++)
        std::cout << ir[i] << " ";
    std::cout << "\n";
}
void RandomArray::freeArray()
{
    delete[] ir; 
}
