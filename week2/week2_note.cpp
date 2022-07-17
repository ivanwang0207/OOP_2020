#include <iostream>  
#include <string>
#include <cstdlib> // call the random number generation function rand
#include <ctime> //uses the computer’s internal clock to return an integer
using namespace std;  


class Student
{
    public: std::string name = "ivan";
    public: short id = 0 ;
    public: short age = 21;
};

struct Student_struct
{  
    std::string name = "ivan";
    short id = 0 ;
    short age = 21; 
};


int main()  
{
    Student a1;
    cout << "Student info:" << endl;
    cout << "\t name:" << a1.name << endl;
    cout << "\t id:" << a1.id << endl;
    cout << "\t age:" << a1.age << endl;
    

    Student a2;
    a2.name = "handsome wang";
    a2.id = 13;
    a2.age = 25;

    cout << "Student info:" << endl;
    cout << "\t name:" << a2.name << endl;
    cout << "\t id:" << a2.id << endl;
    cout << "\t age:" << a2.age << endl;

    Student* a3;
    a3 = &a2;

    cout << "Student info:" << endl;
    cout << "\t name:" << a3->name << endl; //or using (*a3).name, dereference a3
    cout << "\t id:" << a3->id << endl;
    cout << "\t age:" << (*a3).age << endl;

    /* 
    string s = "abc1w";
    cout << s << endl;

    string *pstring; 
    pstring = &s; 

    cout<< pstring << endl;
    cout<< *pstring << endl; // (*) dereference address 

    int i;
    int* ip = &i; //ensure that you are working with the availible memory address
    *ip = 10; // dereference ip, and do whatever u like
    cout << *ip << endl;
    cout << i << endl;

    const int a = 10;
    
    int k = 10001;
    auto j = k;
    cout << j <<endl; //g++ -std=c++11 Sizeof.cpp
    */

    /*
    int i;
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; //x has type const int 
    decltype(i) a; // a is an uninitialized int 
    decltype(cj) y = x;
    */

    /*
    int i;      
    for (i=0; i<10; i++)
    cout << rand()%6 + 1 << ' ';
    cout << RAND_MAX << endl;
    cout << endl;
    */
    return 0;  

}