#include <iostream>
#include "Square.h"
#include "Rectangle.h"

using namespace std;

int main () {
    cout << "Please input the side of the square: ";
    int side;
    cin >> side;

    Rectangle rect;
    Square sqr(side);
    rect.convert(sqr);

    cout << "The converted Rectangle has:" << endl;
    rect.print();
    return 0;
}