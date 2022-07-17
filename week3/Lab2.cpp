#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Triangle.h"

using namespace std;

int main()
{
    int v_size;
    cout << "How many Triangles will you input?";
    cin >> v_size;
    vector<Triangle> itri(v_size);
    
    auto beg = begin(itri);
    auto last = end(itri);

    size_t cnt = 1;

    while (beg != last){      
        cout << "Input for the " << cnt << " triangle:" << endl;
        cout << "       Please input the x&y coordinates of the 1st vertex:";
        cin >> beg->A.x >> beg->A.y;
        cout << "       Please input the x&y coordinates of the 2nd vertex:";
        cin >> beg->B.x >> beg->B.y;
        cout << "       Please input the x&y coordinates of the 3rd vertex:";
        cin >> beg->C.x >> beg->C.y;
        
        double ab = beg->pow_length (beg->A, beg->B);
        double bc = beg->pow_length (beg->B, beg->C);
        double ca = beg->pow_length (beg->A, beg->C);
        
        beg->success(ab,bc,ca); 
        
        cnt++;
        beg++;
    }
    cout << "Done reading Triangles." << endl;

    for (auto i=0; i!=v_size; i++)
    {
        if (itri[i].right)
            cout << "Triangle "<< i+1 << " is a right triangle!!" << endl;
        else 
            cout << "Triangle "<< i+1 << " is NOT a right triangle!!" << endl;
    }     
    return 0;
}