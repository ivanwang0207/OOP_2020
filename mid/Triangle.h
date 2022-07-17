#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vertex.h"
#include <math.h>

struct Triangle{
	Vertex A;
	Vertex B;
	Vertex C;
	bool right;
};

#endif
