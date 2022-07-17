#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    /*
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2(v1);
    vector<int> v3(10,100);
    
    v1.push_back(6);
    v1[3] = 20;

    for(auto i : v1)
        cout << i <<endl;

    */
    /*
    string word;
    vector<string> text;
    while (cin >> word) // CTRL+D to end loop
        text.push_back(word);

    for (auto s : text)
        if (s.size() > 4) cout << s << endl;
    */
   
    vector<int> v{ 1, 2, 3 };
    for (decltype(v.size()) idx = 0; idx != v.size(); ++idx)
    {
        v[idx] = v[idx] * v[idx];
        cout << v[idx] << " ";
    }
    cout << endl;
    return 0;
}