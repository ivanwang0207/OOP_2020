#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("text.txt");

    if (!fin)
    {
        cerr << "cannot open input.txt" << endl;
        return -1;
    }

    string line;
    vector<string> text;
    /*
    while(getline(fin,line)) //print out the whole text
        cout << line <<endl;
    */
    
    while (getline(fin,line)) 
    {
        text.push_back(line);
    }

    // print each line in text up to the first blank line
    cout << "The first paragraph of the input file is" << endl << endl;
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it << endl;

    return 0;
}