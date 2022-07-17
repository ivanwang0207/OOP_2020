#include <string>
#include "stdlib.h"
#include "time.h"
#ifndef PERSON_H
#define PERSON_H

class Person{
    std::string name;
    int age; 
public:
    Person(std::string tmps,int tmpn):name(tmps),age(tmpn){}   
    std::string getname() const {return name;}
    int getage() const {return age;}    
    //friend class PersonVector; // to get access to the private access to person.h
};
#endif
