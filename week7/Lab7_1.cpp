#include <iostream>
#include <set>
#include <vector>
#include "VecFour.h"
using namespace std;

int main()
{
    VecFour a = VecFour(1.0, 1.0, 2.0, 2.0) ;
    cout << "The vector \'a\' is: " << a << endl ;
    VecFour b ;
    cout << "Please input a vector: " ;
    cin >> b ;      // 0.0,1.0,2.0,5.0
    cout << "The vector you input is: " << b << endl ;
    VecFour c = a*2.5;
    cout << "The vctor \'c\' is : " << c << endl ;
    c *= a;
    cout << "The vector \'c\' changes to : " << c << endl ;
    VecFour d ;     // 0.0,0.0,0.0,0.0
    cout << "The vector \'d\' is : " << d << endl ;
    set<VecFour> coll { a, b, c, d };
    for ( const auto& e : coll)
        cout << e << " ";
    cout << endl;
    return 0;
}