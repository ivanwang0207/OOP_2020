
#ifndef SQUARE_H
#define SQUARE_H
class Rectangle;
#include <iostream>

class Square{
    friend class Rectangle;
    int side;
public:
    Square(int i):side(i){}
};
#endif
