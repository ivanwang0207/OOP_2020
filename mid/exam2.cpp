#include "Vertex.h"
#include "Triangle.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void isRT(vector<Triangle>::iterator, vector<Triangle>::iterator);
const double distance(const Vertex&, const Vertex&);

int main(){

	string isTri;
	bool sw = true;
	size_t cnt = 1;
	vector<Triangle> itri;		

	cout << "input triangle? ";
	cin >> isTri;

	while(sw){
		
		cout << "Input for the " << cnt << " triangle:" << endl;
		Triangle temp;
		cout << "	Please input the x & y coordinates of the 1st vertex: ";
		cin >> temp.A.x >> temp.A.y;
		cout << "	Please input the x & y coordinates of the 2nd vertex: ";
		cin >> temp.B.x >> temp.B.y;
		cout << "	Please input the x & y coordinates of the 3rd vertex: ";
		cin >> temp.C.x >> temp.C.y;
		itri.push_back(temp);

		cout << "input triangle? ";		
		cin >> isTri;
		if (isTri == "no")
			break;
		cnt++;	
	}

	cout << "Done reading Triangle.\n";
	auto beg = begin(itri);
	auto last = end(itri);
	isRT(beg,last);
	return 0;
}

void isRT(vector<Triangle>::iterator be, vector<Triangle>::iterator en){
	size_t cnt = 1; 
	for(be; be!=en; be++){
		const auto ab = distance(be->A, be->B);
		const auto bc = distance(be->B, be->C);
		const auto ca = distance(be->C, be->A);
		
		bool is_triangle = false;
		bool ab_tangent = false;
		bool bc_tangent = false;
		bool ca_tangent = false;	
		
		if(ab+bc > ca && bc +ca > ab && ab+ ca >bc){
			is_triangle = true;		
		}
		if (std::abs(bc*bc + ca*ca - ab*ab)< 1.e-12){
			ab_tangent = true;		
		}
		else if (std::abs(ab*ab + ca*ca - bc*bc)< 1.e-12){
			bc_tangent = true;		
		}
		else if (std::abs(ab*ab + bc*bc - ca*ca)< 1.e-12){
			ca_tangent = true;		
		}

		if((ab_tangent || bc_tangent || ca_tangent) && is_triangle){
			cout << "Triangle "<< cnt << " is a right triangle!\n";
			be->right = true;
			if(ab_tangent)
				cout << "THe right angle of triangle " << cnt << " is at the Vertex3\n";
			else if(bc_tangent)
				cout << "THe right angle of triangle " << cnt << " is at the Vertex1\n";
			else 
				cout << "THe right angle of triangle " << cnt << " is at the Vertex2\n";
		}
		else
			cout << "Triangle " << cnt << " is NOT a right triangle1\n";
		cnt++;
	}
	
}

const double distance(const Vertex& begin, const Vertex& end){
	const auto dx = end.x - begin.x;
	const auto dy = end.y - begin.y;
	return std::sqrt(dx*dx+dy*dy);
}




