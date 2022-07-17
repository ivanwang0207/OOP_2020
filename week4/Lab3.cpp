#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void lab43();
int lab43(int& n);
void lab43(string s);

int main(){
 lab43();

 int i = 2;
 lab43(i);
 cout << "main: i++ = " << i << endl;

 string s = "abcde";
 lab43(s);
 lab43("fghij");
 return 0;
}

void lab43(){
    cout << "no arg version!"<< endl;
}

int lab43(int& n){
    n++;
    cout << "lab43: i++ = " << n << endl;
    return n;
}
void lab43(string s){
    cout << "lab43(s): " << s << endl;
}
