#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
   srand(time(0));
   int n;
   
   cout << "Please give how many random numbers you want: ";
   cin >> n;
   
   int upper, lower;
   cout << "Please give the lower and upper bounds: ";
   
   cin >> lower >> upper;
   
   
   
   for (int i=0; i<n; i++)
      cout << lower + (int)(1.0*(upper - lower + 1)*rand()/RAND_MAX) << ' ';
   cout << endl;
   return 0;
}
