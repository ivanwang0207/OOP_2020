#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int intA[3] = {1,2,4}; 

    //intA can be seen as a pointer (to the first element in an array)
    cout << *(intA+2) << endl; //this points to the third element in an array

        for (auto it = begin(intA); it !=end(intA); it++)
            cout << *it << endl;

    return 0;
}