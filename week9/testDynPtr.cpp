#include <iostream>

using namespace std;

int main(){
  int** intDyPtr;
  intDyPtr = new int*[10];

  for(int i = 0; i < 10; ++i)
    intDyPtr[i] = new int(i);

  cout << "Example code for dynamic array storing pointers! " << endl;

  // clean up for int elements
  for(int i = 0; i < 10; ++i)
    delete intDyPtr[i];

  // clean up for the pointers
  delete[] intDyPtr;
}
