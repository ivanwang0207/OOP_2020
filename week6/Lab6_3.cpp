#include <iostream>
using namespace std;

class OOPClass
{
    static int count;
public:
    OOPClass();
    static void printCount();
};


int OOPClass::count = 0;

void OOPClass::printCount()
{
    cout << "Instance of OOPClass: " << count << "\n";
}

OOPClass::OOPClass() //default constructor 
{
    OOPClass::count++;
    cout << "Instance of OOPClass created.\n";
}

int main()
{
    OOPClass a1;
    OOPClass a2;
    OOPClass a3;
    OOPClass::printCount();

    OOPClass a4;
    OOPClass a5;
    OOPClass::printCount();
    return 0;
}