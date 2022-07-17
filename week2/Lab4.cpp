#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;


int main() {
    
    Triangle tra;

    cout << "plz input the x&y coordinates of the 1st vertex: ";
    cin >> tra.A.x;
    cin >> tra.A.y;

    cout << "plz input the x&y coordinates of the 2nd vertex: ";
    cin >> tra.B.x;
    cin >> tra.B.y;

    cout << "plz input the x&y coordinates of the 3rd vertex: ";
    cin >> tra.C.x;
    cin >> tra.C.y;

    double len_ab = tra.length (tra.A, tra.B);
    double len_bc = tra.length (tra.B, tra.C);
    double len_ca = tra.length (tra.A, tra.C);

    if (len_ab + len_bc <= len_ca || len_bc + len_ca <= len_ab || len_ab + len_ca <= len_bc) 
        cout << "These points cannot form a triangle!!" << endl;

    else
        cout << "These points can form a triangle!!!" << endl;


    return 0;
}