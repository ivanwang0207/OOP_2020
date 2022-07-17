#include <string>
#include <iostream>
#include <algorithm>
class CrazyRichAsian 
{
private:
    std::string *name;
    int age;

public:
    CrazyRichAsian()
    {
        name = new std::string();
    }
    CrazyRichAsian(const std::string& s, int a)
    {
        age = a;
        name = new std::string();
        *name = s;
    }

    CrazyRichAsian(const CrazyRichAsian& rhs)
    {
        // copy constructor 
        this->age = rhs.age;
        this->name = new std::string();
        *name = *(rhs.name);
    }

    CrazyRichAsian& operator=(const CrazyRichAsian& rhs)
    {
        // assign constructor
        if(this != &rhs)
        {
            this->age = rhs.age;
            delete this->name;
            this->name = new std::string();
            *name = *(rhs.name);
        }
        return *this;
    }

    /* you cannot change the destructor */
    ~CrazyRichAsian() {delete name;}

    void printString()
    {
        std::cout << "Name: " << *(this->name) << ", age: " << this->age << std::endl;
    }
    void change(const std::string& s)
    {
        delete this->name;
        this->name = new std::string();
        *(this->name) = s;
    }
};

using namespace std;

CrazyRichAsian goToSingapore(CrazyRichAsian& n){
    CrazyRichAsian ret;
    ret = n;
    n.change("THE Nick Yang");
    cout << "inFunc goToSingapore: ";
    ret.printString();
    return ret;
}

int main() {
    CrazyRichAsian nick("Nick Yang",30);
    cout << "Before goToSingapore: ";
    nick.printString();

    goToSingapore(nick);
    cout << "After  goToSingapore: ";
    nick.printString();
    CrazyRichAsian q(nick);
    cout << "After q(nick): " << endl;
    nick.printString();
    q.printString();
    nick = nick;
    cout << "After nick = nick: " << endl;
    nick.printString();
    cout << endl;
}
