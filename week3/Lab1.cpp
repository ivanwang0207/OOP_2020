#include <iostream>
#include <string>
#include <vector>
//#include "Vertex.h"
#include "Triangle.h"

using namespace std;

int main()
{
    const size_t array_size = 3;
    Triangle Tri[array_size]; 

    Triangle *pbeg = begin(Tri), *pend = end(Tri);
    size_t cnt = 1;

    while (pbeg != pend){      
        cout << "Input for the " << cnt << " triangle:" << endl;
        cout << "       Please input the x&y coordinates of the 1st vertex:";
        cin >> pbeg->A.x >> pbeg->A.y;
        cout << "       Please input the x&y coordinates of the 2nd vertex:";
        cin >> pbeg->B.x >> pbeg->B.y;
        cout << "       Please input the x&y coordinates of the 3rd vertex:";
        cin >> pbeg->C.x >> pbeg->C.y;

        double ab = pbeg->pow_length (pbeg->A, pbeg->B);
        double bc = pbeg->pow_length (pbeg->B, pbeg->C);
        double ca = pbeg->pow_length (pbeg->A, pbeg->C);
        
        pbeg->success(ab,bc,ca); 
        
        cnt++;  
        pbeg++;
    }
    cout << "Done reading Triangles." << endl;
    
    for (auto i=0; i!=array_size; i++)
    {
        if (Tri[i].right)
            cout << "Triangle "<< i+1 << " is a right triangle!!" << endl;
        else 
            cout << "Triangle "<< i+1 << " is NOT a right triangle!!" << endl;
    }     
    return 0;
}