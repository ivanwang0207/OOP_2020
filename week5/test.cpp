#include<iostream>
using namespace std;

class A {
    public:
    A() = default;
    A(int i):a(i){}
    int a;
};

int main() {
    A s_obj;
    cout << "stack: " << s_obj.a << endl;

    A s_obj_init(35);
    cout << "stack: " << s_obj_init.a << endl; 

    A* obj = new A; // default initialized
    cout << "lucky: " << obj->a << endl;
    obj->a = 10;
    delete obj;
    
    obj = new A; // default initialized
    cout << "garbage: " <<obj->a << endl;
    obj->a = 10;
    delete obj;

    obj = new A(); // value initialized
    cout << "value init: " << obj->a << endl;
    delete obj;
}

