#include <string>
#include <iostream>  
using namespace std;  

int main(){

    int cdl;
    int cdu;

    cout << "plz input the range of celsius temperature values: ";    
    cin >> cdl;
    cin >> cdu;

    cout << "Celsius Fahrenheit" << endl;
    for (int i=cdl; i< cdu + 1 ; i++){
        cout << i << "\t" << i*9.0/5 + 32 << endl;        
    }    
    return 0;
}