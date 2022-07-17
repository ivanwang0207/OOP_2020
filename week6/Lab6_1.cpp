#include <iostream>
#include <string>

using namespace std;

struct IntArray{
    int* ia;
    int n;
};

IntArray creatIntArray();
int findMax(const IntArray&);
void printIntArray(const IntArray&);
void deleteIntArray(IntArray&);

int main(){
    IntArray intArray = creatIntArray();
    int i = findMax(intArray);
    cout << "Max value in integer array is: " << intArray.ia[i] << endl;
    printIntArray(intArray);
    deleteIntArray(intArray);
    return 0;
}

IntArray creatIntArray(){
	cout << "How many integers do you want to input: ";
	IntArray intarr;
	cin >> intarr.n;
	intarr.ia = new int[intarr.n]; //dynamic allocation of ia
	cout << "Please input the integers: ";
	for(int i = 0; i < intarr.n; i++){
		cin >> intarr.ia[i];
	}
	return intarr;
}

int findMax(const IntArray& intarr){
    int maidx = 0;
    int val = intarr.ia[0];
    for(int i=0; i!=intarr.n; i++){
        if (intarr.ia[i]>val){
            maidx = i;
            val = intarr.ia[i];
        }           
    }
    return maidx;
}

void printIntArray(const IntArray& intarr){
    for(int i=0; i!=intarr.n; i++){
        cout << intarr.ia[i] << " ";
    }
    cout << "\n";
}

void deleteIntArray(IntArray& intarr){
    delete[] intarr.ia;
}