#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

double average(const vector<int>&);
double standardDev(const vector<int>&);
int isInt(std::string);

int main(){
	cout << "Input positive integers: "<< endl;
	string str;
	vector<int> int_arr;
	while(cin >> str){
		if(str== "Q"){
			break;		
		}
		else{
			int_arr.push_back(isInt(str));	
		}
	}
	cout << "The result: "<< endl;
	cout << "Average = " << average(int_arr) << endl;
	cout << "Standard deviation = "<< standardDev(int_arr) << endl;
	return 0;
}

int isInt(std::string str){
		int i = std::stoi(str);
		return i;
}

double average(const vector<int>& iv){
	int sum =0;
	for(auto i = begin(iv); i!=end(iv); i++){
		sum += *i;	
	}
	return sum/(double)iv.size();
}

double standardDev(const vector<int>& iv){
	double mean = average(iv);
	double stdDev = 0;
	
	auto beg = begin(iv);
	auto last = end(iv);
	while(beg != last){
		stdDev += pow(*beg - mean, 2);
		beg++;	
	}
	return sqrt(stdDev/(double)iv.size());
}
