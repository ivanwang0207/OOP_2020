#include <iterator>
#include <iostream>
using namespace std;
int main(){
    const size_t array_size = 10;
    int ia[array_size];
    int *pbeg = begin(ia), *pend = end(ia);
    size_t cnt = 0;
    cout << "The contents are: ";
    while (pbeg != pend){
        *pbeg = cnt;
        cnt++;
        cout << *pbeg++ << ' ';
    }
    cout << endl;
    return 0;
}