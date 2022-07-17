#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double average(vector<int>& iv){
	double sum = 0;
	for(auto i : iv)
		sum += i;
	double ave = sum/iv.size();
	return ave;
}

double standardDev(vector<int>& iv){
	double sta;
	double ave = average(iv);
	double sum;
	for(auto i : iv)
		sum += pow((i - ave), 2);
	sta = sqrt(sum/iv.size());
	return sta;
}
int main(){
	cout << "Input positive integers: " << endl;
	int temp;
	vector<int> inputData;
	while(cin >> temp && temp != -1)
		inputData.push_back(temp);
	cout << endl;
	cout << "The result:" << endl;
	cout << "Average =" << average(inputData) << endl;
	cout << "Standard deviation =" << standardDev(inputData) << endl;
}