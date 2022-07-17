#include <iostream>
#include <cmath>
#include <vector>

#include "Vertex.h"
#include "Triangle.h"

const double distance(const Vertex& begin, const Vertex& end);

const bool equal_to(const double& lhs, const double& rhs, const double& epsilon = 1.e-12);

int main()
{	
	int n;
	std::cout << "How many Triangles will you input? ";
	std::cin >> n;

	std::vector<Triangle> t(n);

	int cnt = 1;
	for(auto iter = t.begin(); iter != t.end(); ++iter){
		std::cout << "Input for the " << cnt << " triangle:\n";

		std::cout << "\tPlease input the x & y coordinates of the 1st vertex: ";
		std::cin >> iter->a.x >> iter->a.y;

		std::cout << "\tPlease input the x & y coordinates of the 2nd vertex: ";
		std::cin >> iter->b.x >> iter->b.y;

		std::cout << "\tPlease input the x & y coordinates of the 3rd vertex: ";
		std::cin >> iter->c.x >> iter->c.y;

		cnt++;
	}
	
	std::cout << "Done reading Triangles.\n";

	cnt = 1;
	for(auto iter = t.begin(); iter != t.end(); ++iter){
		const auto ab = distance(iter->a, iter->b);
		const auto bc = distance(iter->b, iter->c);
		const auto ca = distance(iter->c, iter->a);

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
			std::cout << "Triangle "<< cnt << " is a right triangle!\n";
			iter->right = true;

			if (ab_tangent)
				std::cout << "The right angle of triangle " << cnt << " is at the Vertex3\n";
			else if (bc_tangent)
				std::cout << "The right angle of triangle " << cnt << " is at the Vertex1\n";
			else
				std::cout << "The right angle of triangle " << cnt << " is at the Vertex2\n";
		}
		else
			std::cout << "Triangle "<< cnt << " is NOT a right triangle!\n";

		cnt++;
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

