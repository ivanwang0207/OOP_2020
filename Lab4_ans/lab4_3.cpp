#include <iostream>
#include <string>

using namespace std;

void lab43();
void lab43(int& i);
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
	cout << "no arg version!" << endl;
}
void lab43(int& i){
	cout << "lab43: i++ = " << ++i << endl;
}
void lab43(string s){
	cout << "lab43(s): " << s << endl;
}