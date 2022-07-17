#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string word;
    vector<int> ints = {0,1,2,3,4};
    //auto i_ite = ints.cbegin(); //constant iterator
    auto i_ite = ints.end(); // vector<int>::iterator 
    *(i_ite - 1) = 10;
    cout << *(i_ite - 1) << endl;

    for(auto it = ints.begin(); it != ints.end(); it++)
        cout << *it << endl;

    return 0;
}