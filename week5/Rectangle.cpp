#include "Rectangle.h"
#include "Square.h"
#include <iostream>

using namespace std;

void Rectangle::convert(Square sqr){
    int side = sqr.side;
    height = side;
    width = side;
}

void Rectangle::print(){
    cout << "height: "<< height <<" width: "<< width << " area: "<< area() << endl;
}

double Rectangle::area(){
    return height * height ;
}