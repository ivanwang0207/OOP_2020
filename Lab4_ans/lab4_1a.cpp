#include <iostream>
#include <cmath>

using namespace std;

double average(int arr[], size_t s){
	double sum = 0;
	for(size_t i = 0; i < s; i++)
		sum += arr[i];
	double ave = sum/s;
	return ave;
}

double standardDev(int arr[], size_t s){
	double sta;
	double ave = average(arr,s);
	double sum;
	for(size_t i = 0; i < s; i++)
		sum += pow((arr[i] - ave), 2);
	sta = sqrt(sum/s);
	return sta;
}
int main(){
	const size_t ss = 8;
	int a[ss] = {3, 10, 40, 5, 12, 7, 22,39};
	cout << "The result:" << endl;
	cout << "Average =" << average(a, ss) << endl;
	cout << "Standard deviation =" << standardDev(a, ss) << endl;
}