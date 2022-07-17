#include <iostream>
#include <memory>

using namespace std;
/*
int main(){
    int k;
    cout << "give me size of array: ";
    cin >> k;

    int *br = new int[k](); //value initialization
    //int *br = new int[5](); //all elements are initialized to 0
    //int *br = new int[5]{1}; //the first element is 1, the others are 0
    br[0] = 50;
    cout << br[0] << endl;

    delete[] br;

    return 0;
}*/
class StringBad{
private:
    string str;
    int len;
    static int num_strings;

public:
    StringBad():str(""),len(0){num_strings++;}
    StringBad(string s, int i):str(s),len(i){num_strings++;}
    static int getNum(){return num_strings;}
};

int StringBad::num_strings = 0; //static object initializes 

int main(){
    StringBad olivia;
    cout << StringBad::getNum() << endl;
    StringBad greg;
    cout << StringBad::getNum() << endl;
    StringBad dave;
    cout << StringBad::getNum() << endl;

    return 0;
}