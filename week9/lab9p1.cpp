#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual string shapeName() const = 0;
    //friend std::ostream& operator << (std::ostream& out, const Shape& s);
};


std::ostream& operator << (std::ostream& out, const Shape* s) {
    out << s->shapeName() << "\'s area is " << s->getArea() << "\n";
    return out;
}

class Rectangle : public Shape {
    double length;
    double height;
public:
    Rectangle(double a, double b):length(a), height(b){}
    virtual double getArea() const{  return length*height;  }
    virtual string shapeName() const{  return "Rectangle";  }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double a):radius(a){}
    virtual double getArea() const{  return radius*radius*3.1415;  }
    virtual string shapeName() const{  return "Circle";  }
};

class Triangle : public Shape {
    double side1;
    double side2;
    double side3;
public:
    Triangle(double a, double b, double c): side1(a), side2(b), side3(c){}
    virtual double getArea() const{
        double p = (side1 + side2 + side3)/2;
        return sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }
    virtual string shapeName() const{  return "Triangle";  }
};

int main(){
  vector<Shape*> vs;

  Rectangle r(10,20);
  Circle c(10);
  Triangle t(18,30,24);

  vs.push_back(&r);
  vs.push_back(&c);
  vs.push_back(&t);

  for(auto s : vs)
      cout << s;

  return 0;
}
