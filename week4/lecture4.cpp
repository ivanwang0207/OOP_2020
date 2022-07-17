#include <iostream>
#include <iterator>

using namespace std;

void showArray(int[],size_t);
void showArrayP(int*, size_t);

template <std::size_t arr_size>
void showArray(int (&)[arr_size]);

int main(){
    int i[] = {1,2,3,4,5};
    showArray(i,5);
    showArrayP(i,5);
    showArray(i);
    return 0;
}

void showArray(int array[], size_t size){
    for(size_t i = 0; i <size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void showArrayP(int* array, size_t size){
    for(size_t i= 0; i <size; i++){
        cout << *array++ << " ";
    }
    cout << endl;
}

template <std::size_t arr_size>
void showArray(int (&array)[arr_size]){
    for(auto i=begin(array); i!=end(array); i++){ //now we know the size of array in within a function
        cout <<*i << " ";
    }
    cout << endl;
}