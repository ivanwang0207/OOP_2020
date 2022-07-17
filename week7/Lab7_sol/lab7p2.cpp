#include <iostream>

using namespace std;

class Vec{ 
    int* v;
    int n; 
public:
    Vec(): n(5){
        //cout << "Vec Default Constructor!" << endl;
        v = new int[n];
        for(int i = 0; i < 5; ++i) v[i] = i;
    }
    Vec(const Vec& rhs){
        //cout << "Vec Copy Constructor!" << endl;
        this->n = rhs.n;
        this->v = new int[this->n];
        for(int i = 0; i < this->n; ++i) this->v[i] = rhs.v[i];
    }
    Vec& operator=(const Vec& rhs){
        //cout << "Vec Assignment Operator!" << endl;
        if(this != &rhs){
            delete[] this->v;
            this->n = rhs.n;
            this->v = new int[this->n];
            for(int i = 0; i < this->n; ++i) this->v[i] = rhs.v[i];
        }
        return *this;
    }
    void show(string s){
        cout << s << ": ";
        for(int i = 0; i < 5; ++i) cout << v[i] << " ";
        cout << endl;
    }
    ~Vec(){  delete[] v; }
};

int main(){
    Vec v;
    v.show("v1");
    
    {
        Vec v2(v);
        v2.show("v2");
    }
    
    {
        Vec v3;
        v3 = v;
        v3.show("v3"); 
    }
    
    v = v;
    
    v.show("after v = v");
}