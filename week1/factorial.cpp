#include <iostream> 

using namespace std; 
int main() 
{     
   int fac =1;     
   int num;     
   cout << "plz input the n number: ";    
   cin >> num;
   if (num >=1)
   {
        cout << "The factor of " << num ;
        while (num >= 1) 
        {         
        fac *= num;                 
        if (num == 1)
            break; 
        num = num -1;   
        } 
        cout  << " is: " << fac << endl;
   }
   else if (num == 0)
        cout << "The factor of " << num << " is: " << fac << endl;   
   else  
        cout << "The factor of " << num << " is: " << -1 << endl;
     
   return 0; 
}