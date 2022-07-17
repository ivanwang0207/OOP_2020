#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Luggage
{
    Luggage(string n, float w): name(n), weight(w){}
    string name;
    float weight;
};

/* use the << for output of the Luggae objects */
ostream& operator <<(ostream& os, const Luggage& l)
{
    os << "Luggage name: " << l.name << ", weight: " << l.weight << "kg" << endl;
    return os;
}


int main()
{
    cout << "Please input how many luggage for your airplane: ";
    int num;
    cin >> num;

    stack<Luggage> lugStack;

    for (int i=0; i!=num; i++)
    {
        cout << "Please input luggage number " << i << endl;
        string name;
        float weight;
        cout << "name: ";
        cin >> name;
        cout << "weight: ";
        cin >> weight;
        Luggage lug(name, weight);
        lugStack.push(lug);
    }
    cout << "Removing luggage off the plane:" << endl;
    while(!lugStack.empty())
    {
        cout << lugStack.top();
        lugStack.pop();
    }

    return 0;
}
