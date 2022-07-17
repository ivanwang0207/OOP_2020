#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Movie
{
    friend ostream& operator << (ostream& s, const Movie& m);
private:
    string name;
    int count = 10;

public:
    Movie(string n, int c)
    {
        this->name = n;
        this->count = c;
    }
    
    bool operator < (const Movie& rhs) const
    {
        return this->count > rhs.count; 
    }
};

ostream& operator << (ostream& strm, const Movie& m)
{
    strm << m.name << ", " << m.count;
    return strm;
} 

map<Movie, string> getInput()
{
    map<Movie, string> result;
    int done = false;
    while (!done)
    {
        string name, rate;
        int count;

        cout << "Please input Movie Name: ";
        cin >> name;
        cout << "Please input Movie view: ";
        cin >> count;
        cout << "Please input Movie rate: ";
        cin >> rate;
        Movie newMovie(name, count);
        result.insert({newMovie, rate});

        cout << "end Movie input (1/0)? ";
        cin >> done;
    }
        
    return result;
}
void show(map<Movie, string>& mv)
{
    int doShow = true;
    while (doShow)
    {
        cout << "How many top viewed Movies to show? ";
        int num;
        cin >> num;
        auto it = mv.begin();
        while(num--)
        {
            cout << it->first << ": " << it->second << endl;
            it++;
        }
        cout << "show again? (1/0) ";
        cin >> doShow;
    }
}

/* You cannot change the main */
int main(){
    map<Movie, string> m = getInput();
    show(m);
}
