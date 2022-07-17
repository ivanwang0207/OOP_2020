#include <iostream>
#include <cmath>

#include "Vertex.h"
#include "Triangle.h"

const double distance(const Vertex& begin, const Vertex& end);

const bool equal_to(const double& lhs, const double& rhs, const double& epsilon = 1.e-12);

int main()
{
	Triangle t[3];

	for(int i = 0; i < 3; i++){
		std::cout << "Input for the " << i+1 << " triangle:\n";

		std::cout << "\tPlease input the x & y coordinates of the 1st vertex: ";
		std::cin >> t[i].a.x >> t[i].a.y;

		std::cout << "\tPlease input the x & y coordinates of the 2nd vertex: ";
		std::cin >> t[i].b.x >> t[i].b.y;

		std::cout << "\tPlease input the x & y coordinates of the 3rd vertex: ";
		std::cin >> t[i].c.x >> t[i].c.y;
	}
	
	std::cout << "Done reading Triangles.\n";


	for(int i = 0; i < 3; i++){
		const auto ab = distance(t[i].a, t[i].b);
		const auto bc = distance(t[i].b, t[i].c);
		const auto ca = distance(t[i].c, t[i].a);

		bool is_triangle = false;
		bool ab_tangent = false;
		bool bc_tangent = false;
		bool ca_tangent = false;

		// define whether is a triangle or not
		if (ab+bc > ca && bc+ca > ab && ab+ca > bc)
		{
			is_triangle = true;
		}

		// ab state
		if (equal_to(bc*bc + ca*ca, ab*ab))
		{
			ab_tangent = true;
		}
		// bc state
		else if (equal_to(ab*ab + ca*ca, bc*bc))
		{
			bc_tangent = true;
		}
		// ca state
		else if (equal_to(ab*ab + bc*bc, ca*ca))
		{
			ca_tangent = true;
		}


		if ((ab_tangent || bc_tangent || ca_tangent) && is_triangle)
		{
			std::cout << "Triangle "<< i+1 << " is a right triangle!\n";
			t[i].right = true;
			
			if (ab_tangent)
				std::cout << "The right angle of triangle " << i+1 << " is at the Vertex3\n";
			else if (bc_tangent)
				std::cout << "The right angle of triangle " << i+1 << " is at the Vertex1\n";
			else
				std::cout << "The right angle of triangle " << i+1 << " is at the Vertex2\n";
		}
		else
			std::cout << "Triangle "<< i+1 << " is NOT a right triangle!\n";
	}

}

const bool equal_to(const double& lhs, const double& rhs, const double& epsilon)
{
	return std::abs(lhs - rhs) < epsilon;
}

const double distance(const Vertex& begin, const Vertex& end)
{
	const auto dx = end.x - begin.x;
	const auto dy = end.y - begin.y;
	
	return std::sqrt(dx*dx + dy*dy);
}

