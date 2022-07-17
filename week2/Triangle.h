#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vertex.h"
#include <math.h>

struct Triangle {
    Vertex A;
    Vertex B;
    Vertex C;

    double length (Vertex a, Vertex b)
    {
        return sqrt(pow((a.x - b.x),2)+ pow((a.y - b.y),2));
    }
};
#endif