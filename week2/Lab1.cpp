#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>  
using namespace std;  

int main()  {

    int num;
    int lb;
    int ub;
    cout << "plz give how many random numbers you want: ";    
    cin >> num;
    cout << "plz give the lower and upper bounds: ";   
    cin >> lb;
    cin >> ub;

    srand(time(0)); 

    int i;      
    for (i=0; i<num; i++)
        cout << rand()% (ub-lb+1)+lb << ' ';
        //cout << (int)(lb + 1.0 * rand()/RAND_MAX * (ub - lb + 1)) << " ";
    cout << endl;
    


    return 0;
}