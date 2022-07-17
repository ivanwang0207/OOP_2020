#include <iostream>
#include <string>
#include <cctype> //test each char. in a string etc.
using namespace std;
int main()
{
    string line;
    cout << "Enter a line of strings: ";
    getline(cin, line);
    for (char& c : line) //just changing the local variable c if it is without "& reference" 
        c = tolower(c);

    cout << "The line in lowercase is: " << line << endl;

    /*
    do 
    {
        cout << "please input some string:";
        cin >> s;
        cout << s << endl;
    }
    while (s != "q" && s != "Q");
    */

    return 0;
}