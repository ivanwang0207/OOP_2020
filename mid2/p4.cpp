#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

void process(vector<string>& v1, list<char>& l1)
{
    //use find_first_of()
    for (auto& str: v1)
    {
        auto it = find_first_of(str.begin(), str.end(), l1.begin(), l1.end());
        str.erase(it, str.end());   
    }  
    for (auto& str: v1)
    {
        cout << str << endl;
    }
}

int main(){
  cout << "Please input how many words in your sentence: ";
  int n;
  cin >> n;

  vector<string> v1;
  list<char> l1 {'.', ',', '!', '\''};

  string word;
  cout << "Please input you sentence: ";
  for(int i = 0; i < n; ++i){
    cin >> word;
    v1.push_back(word);
  }

  process(v1, l1);
}
