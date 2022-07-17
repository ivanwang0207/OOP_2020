#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

double average(const vector<int>&);
double standardDev(const vector<int>&);
int isInt(std::string);

int main(){

    cout << "Input positive integers:" << endl;
    string s;
    vector<int> int_arr;

    while(cin >> s){
        try{
            int a = isInt(s);
            int_arr.push_back(a);   
        }
        catch(exception& e) {
            break;
        }      
    }

    cout << "The result:" << endl;
    cout << "Average = "<<average(int_arr) <<endl;
    cout << "Standard deviation = " <<standardDev(int_arr)<< endl;
}

int isInt(std::string s){
        return std::stoi(s);
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