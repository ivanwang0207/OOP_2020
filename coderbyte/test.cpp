#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <functional>

using namespace std;

struct node{
    int value;
    node *next;
};

int main() {

    // Q1
    int foo[4] = {2,3,5,9};
    printf("%d,%d", *foo+2, *(foo+2));
    cout << endl;

    // Q2
    int nMask = 0xffff0000;
    int nData = 386; 
    int nResult = nData & ~( nMask >> 8);
    
    cout << nResult << endl;

    // Q3
    int v1 = 3 << 2; //*2^2 
    int v2 = 3%2; //1
    int v3 = 3|2; //11 OR 10 = 11 

    printf("%d", v2);
    cout << endl;

    // Q4  
    int sz = 4;
    while(--sz >=0){
        cout << sz << "cool" << endl;
    } // assign the value after minusing 1

    // Q5 
    node a, b, c, *p, *q;
    a.next = &b;
    p = &a;
    q = &c;

    // Q6 
    vector<int> data;
    for (int n=0; n<4;++n){
        data.insert(data.begin(),n);
    }

    for (auto it:data){
        printf("%d", it);
    }

    // Q7 

    // In set all the elements are stored in the sorted position, 
    //so the element we will insert will be inserted according to its sorted position.
    set<int> myset;
    myset.insert(1);
    myset.insert(8);
    myset.insert(4);
    myset.insert(8);
    
    for (auto it:myset){
        printf("%d", it);
    }

    // Q8
    int k = 3;
    function<int(int)> lambda1;
    function<int(int)> lambda2;
    lambda1 = [&](int n) -> int
    {
        if (n>1) return lambda1(n-1)*n;
        else{
            if(k>1) --k;
            return 1*k;
        }
    };
    lambda2 = [=,&lambda2](int n) -> int{
        if (n>1) return lambda2(n-1)*n;
        else{
            return 1*k;
        }
    };

    k=2;
    printf("%d", lambda2(4));
    cout << endl;
    printf("%d", lambda1(4));
    cout << endl;
    printf("%d", lambda2(5));
    cout << endl;
    printf("%d", lambda1(5));

    return 0;
}