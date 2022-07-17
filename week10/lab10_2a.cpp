#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    int _x;
    int _y;
    int _width;
    int _height;
public:
    Shape(int x=0, int y=0, int width=0, int height=0): _x(x), _y(y), _width(width), _height(height) {}
    virtual void Draw () = 0 ;
};

class Widget {
private:
    string name;
public:
    Widget() : name("Widget") {}
    void drawCircle(int x, int y, int r) {
        cout << name << " is drawing a Circle whose radius is " << r << " at (" << x << ", " << y << ")." << endl;
    }
    void drawSquare(int x, int y, int l) {
        cout << name << " is drawing a Square whose length is " << l << " at (" << x << ", " << y << ")." << endl;
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle() : radius(0) {}
    Circle(int r, int x, int y) : radius(r) {
        _x = x;
        _y = y;
    }
    void Draw() {
        Widget a;
        a.drawCircle(_x, _y, radius);
    }
};

class Square : public Shape, private Widget {
private:
    int length;
public:
    Square() : length(0) {}
    Square(int l, int x, int y) : length(l) {
        _x = x;
        _y = y;
    }
    void Draw() {
        drawSquare(_x, _y, length);
    }
};

int main() {

    Circle A(25,0,0);
    A.Draw();

    Square B(50,100,100);
    B.Draw();

    return 0;
}