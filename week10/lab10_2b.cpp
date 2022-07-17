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
    virtual void Draw () = 0;
};

class Widget {
protected:
    string name;
public:
    Widget(): name("Widget") {}
    virtual void drawCircle(int x, int y, int r) const {
        cout << name << " is drawing a Circle whose radius is " << r << " at (" << x << ", " << y << ")." << endl;
    }
    virtual void drawSquare(int x, int y, int l) const {
        cout << name << " is drawing a Square whose length is " << l << " at (" << x << ", " << y << ")." << endl;
    }
};

class AWidget : public Widget {
public:
    AWidget(): Widget() { name = "AWidget"; }
    void drawCircle(int x, int y, int r) const override {
        cout << name << " is drawing a Circle whose radius is " << r << " at (" << x << ", " << y << ")." << endl;
    }
    void drawSquare(int x, int y, int l) const override {
        cout << name << " is drawing a Square whose length is " << l << " at (" << x << ", " << y << ")." << endl;
    }
};

class Circle : public Shape {
private:
    int radius = 0;
    Widget* _w;
public:
    Circle() : radius(0) {}
    Circle(int r, int x, int y, Widget* w) {
        radius = r;
        _x = x;
        _y = y;
        _w = w;
    }
    void Draw() { _w->drawCircle(_x, _y, radius); }
};

class Square : public Shape, private AWidget {
private:
    int length;
public:
    Square() : length(0) {}
    Square(int l, int x, int y) {
        length = l;
        _x = x;
        _y = y;
    }
    void Draw() { drawSquare(_x, _y, length); }
};

int main() {
    
    Widget* a = new AWidget();
    
    Circle A(25,0,0,a);
    A.Draw();

    Square B(50,100,100);
    B.Draw();
    
    delete a;
    return 0;
}