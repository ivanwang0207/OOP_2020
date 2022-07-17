#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

double average(const vector<int>&);
double standardDev(const vector<int>&);

int main(){

    cout << "Input positive integers:" << endl;
    int num;
    vector<int> int_arr;

    while(cin >> num){
        if(num == -1)
            break;
        else       
            int_arr.push_back(num);       
    }

    cout << "The result:" << endl;
    cout << "Average = "<<average(int_arr) <<endl;
    cout << "Standard deviation = " <<standardDev(int_arr)<< endl;
}


double average(const vector<int>& iv){
    int sum = 0;
    for (auto i = begin(iv); i!= end(iv); ++i)
        sum += *i;    
    return sum/(double)iv.size();
}

double standardDev(const vector<int>& iv){
    
    double mean = average(iv);
    double standardDeviation = 0;
    
    auto beg = begin(iv);
    auto last = end(iv);
    while(beg != last){
        standardDeviation += pow( *beg - mean , 2);
        beg++;
    }
    return sqrt(standardDeviation / (double)iv.size());   
}