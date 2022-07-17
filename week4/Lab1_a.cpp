#include <iostream>
#include <iterator>
#include <cmath>

using namespace std;

double average(int*,size_t);
double standardDev(int*, size_t);

int main(){

    int i[8] = {3, 10, 40, 5, 12, 7, 22, 39};
    cout << "The result:" << endl;
    cout << "Average = "<<average(i,8) << endl;
    cout << "Standard deviation = " << standardDev(i,8) << endl;
}

double average(int* arr, size_t num){
    int sum = 0;
    for (size_t i = 0; i < num; ++i){
        sum += *arr++;
    }
    return sum/(double)num;
}

double standardDev(int* arr, size_t num){
    
    double mean = average(arr,num);
    double standardDeviation = 0;
    for(size_t i = 0; i < num; ++i){
        standardDeviation += pow( *arr - mean , 2);
        arr++;
    }
    return sqrt(standardDeviation / num);   
}