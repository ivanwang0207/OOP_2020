#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vertex.h"
#include <math.h>

struct Triangle {
    Vertex A;
    Vertex B;
    Vertex C;
    bool right;
    
    double pow_length (Vertex a, Vertex b)
    {
        return pow((a.x - b.x),2)+ pow((a.y - b.y),2);
    }

    void success (double a, double b, double c)
    {
        if( a==0 || b==0 || c==0 ) //when vertices overlap 
            right = false; 
        else
        {
            if (a + b == c || b + c == a || a + c == b) 
                right = true;
            else
                right = false;
        }
    }
};
#endif