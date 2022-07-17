#include "Person.h"
#include <iostream>
#include <vector>
#ifndef PERSONVECTOR_H
#define PERSONVECTOR_H

class PersonVector{
    std::vector<Person> vecp;
public:
    PersonVector() = default;
    void addPersons();
    void displayPersons();
};

void PersonVector::addPersons(){
    int n;
    std::cout<<"How many people to generate? ";
    std::cin>>n;
    for(int i =0 ;i<n ;i++){
        std::string tmpname;
        int tmpage;
        std::cout<< i+1 << "Person to add: ";
        std::cin >> tmpname >> tmpage;
        Person pp(tmpname,tmpage);
        vecp.push_back(pp);
    }
    std::cout<<"Name\tAge\n";
}

void PersonVector::displayPersons(){
    auto beg = begin(vecp);
    auto last = end(vecp);
    while (beg != last){   
        std::cout<<beg->getname()<<"\t"<<beg->getage()<<std::endl;
        beg++;
    }
}
#endif
