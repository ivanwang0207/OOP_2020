#ifndef RECTANGLE_H
#define RECTANGLE_H
class Square;
#include <iostream>

class Rectangle{
    int width;
    int height;
public:
    Rectangle() = default;
    void convert(Square sqr);
    void print();
    double area();
};
#endif
