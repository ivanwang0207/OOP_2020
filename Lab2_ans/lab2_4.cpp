#include <iostream>
#include <cmath>

#include "Vertex.h"
#include "Triangle.h"

int main()
{
	Triangle t;
	std::cout << "Please input the x & y coordinates of the 1st vertex: ";
	std::cin >> t.a.x >> t.a.y;

	std::cout << "Please input the x & y coordinates of the 2nd vertex: ";
	std::cin >> t.b.x >> t.b.y;

	std::cout << "Please input the x & y coordinates of the 3rd vertex: ";
	std::cin >> t.c.x >> t.c.y;

	if((t.b.x-t.a.x)*(t.c.y - t.a.y) - (t.b.y - t.a.y)*(t.c.x - t.a.x) != 0)
    	std::cout << "These points can form a triangle!!\n"; 
		//det(vec(AC),vec(AB))!=0
	else std::cout << "These points cannot form a triangle!!\n";

}
