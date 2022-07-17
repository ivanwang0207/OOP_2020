#include <iostream>
#include <string>
using namespace std;

class Vec{
private:
    int* v;
    int n;
public:
    Vec()
    {
        n = 5;
        v = new int[5];
        for (int i=0; i!=n; i++)
            v[i] = i;
    }
    Vec(const Vec& rhs)
    {
        n = rhs.n;
        
        v = new int[5];
        for (int i=0; i!=n; i++)
        {
            v[i] = rhs.v[i];
        }
        // *v = *rhs.v;
    }
    Vec& operator=(const Vec& rhs)
    {
         if(this != &rhs)
         { 
            n = rhs.n;
            v = new int[5];  
            for (int i=0; i!=n; i++)
            {
                v[i] = rhs.v[i];
            }
         }
         return *this;
    }
    ~Vec()
    {
        delete[] v;
        //v = new int[5];
    }

    void show(string str)
    {
        cout << str << ": ";
        for (int i=0; i!=n; i++)
            cout << v[i] << " ";
        cout << "\n";
    }
};


int main()
{
    Vec v;
    v.show("v1");

    {
        Vec v2 (v);
        v2.show("v2");
    }

    {
        Vec v3;
        v3 = v;
        v3.show("v3");
    }

    v = v;
    
    v.show("after v = v"); 

    return 0;
        
}