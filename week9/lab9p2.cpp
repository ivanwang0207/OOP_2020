#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

class Shape {
public:
    virtual void printArea() const = 0;
    virtual string shapeName() const = 0;
    //friend std::ostream& operator << (std::ostream& out, const Shape& s);
    virtual ~Shape(){}
};


std::ostream& operator << (std::ostream& out, const Shape* s) {
    out << s->shapeName() << "\'s area is ";
    s->printArea();
    cout << "\n";
    return out;
}

class Rectangle : public Shape {
    double length;
    double height;
public:
    Rectangle():length(0),height(0){}
    Rectangle(double a, double b):length(a), height(b){}
    virtual void printArea() const{  cout<< length*height;  }
    virtual string shapeName() const{  return "Rectangle";  }
};

class Square : public Rectangle {
    double length;
public:
    Square():length(0){}
    Square(double a):length(a){}
    virtual void printArea() const{  cout<< length*length;  }
    virtual string shapeName() const{  return "Square";  }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double a):radius(a){}
    virtual void printArea() const{  cout<< radius*radius*3.1415;  }
    virtual string shapeName() const{  return "Circle";  }
};

class ShapeGroup : public Shape {
protected:
    Shape** shapes = nullptr;
    int number = 0;
    int capacity = 100;
public:
    ShapeGroup(){
        shapes = new Shape*[capacity];
    }
    ShapeGroup(int c):capacity(c){
        shapes = new Shape*[capacity];
    }
    ShapeGroup(const ShapeGroup& sg){
        cout << "ShapeGroup::Copy Constructor \n";
        /*
        if (this == &sg)
            return *this;

        if (this != nullptr){
            delete[] shapes;
            capacity = sg.capacity;
            number = sg.number;
        }
        */
        capacity = sg.capacity;
        number = sg.number;

        shapes = new Shape*[capacity];

        for (unsigned index = 0; index != sg.number; ++index)
             shapes[index] = sg.shapes[index];
    }
    virtual void insert(Shape* s){
        shapes[number] = s;
        number++;
    }
    virtual void printArea() const {
    }
    virtual string shapeName() const{  return "ShapeGroup";  }
    //friend std::ostream& operator << (std::ostream& out, const Shape& s);
    virtual ~ShapeGroup(){  delete[] shapes;
        cout << "ShapeGroup::Destructor \n";
    }
};


class ShapeGroupID : public ShapeGroup {
private:
    int* shapeIDs = nullptr;
    int number = 0;
    int capacity = 100;
public:
    ShapeGroupID(){
        shapeIDs = new int[capacity];
    }
    ShapeGroupID(int c):ShapeGroup(c){
        shapeIDs = new int[capacity];
    }
    ShapeGroupID(ShapeGroupID& sgID):ShapeGroup(sgID){
        cout << "ShapeGroupID::Copy Constructor \n";

        capacity = sgID.capacity;
        number = sgID.number;
        shapeIDs = new int[capacity];

        for (unsigned index = 0; index != sgID.number; ++index)
             shapeIDs[index] = sgID.shapeIDs[index];
    }
    virtual void insert(Shape* s){
        ShapeGroup::insert(s);
        shapeIDs[number] = rand() % 100;
        number++;
    }
    virtual void printArea() const {
        for(unsigned index = 0; index != number; ++index){
            cout << shapes[index]->shapeName() << " of id " << shapeIDs[index] << "\'s area: \n";
            //cout<< "\t";
            shapes[index]->printArea(); 
            cout << "\n";
        }
    }
    virtual string shapeName() const{  return "****ShapeGroupID";  }
    //friend std::ostream& operator << (std::ostream& out, const Shape& s);
    virtual ~ShapeGroupID(){
        delete[] shapeIDs;
        cout << "ShapeGroupID::Destructor \n";
    }
};


int main(){
    srand(time(0));
    ShapeGroupID sgID;

    Rectangle* r1 = new Rectangle(10,20);
    Circle* c1 = new Circle(10);
    Square* s1 = new Square(10);
    sgID.insert(r1);
    sgID.insert(c1);
    sgID.insert(s1);

    ShapeGroupID sgID2;
    Circle* c2 = new Circle(5);
    Square* s2 = new Square(5);
    sgID2.insert(c2);
    sgID2.insert(s2);

    ShapeGroupID sgID3(sgID);
    Circle* c3 = new Circle(20);
    Square* s3 = new Square(20);
    sgID3.insert(c3);
    sgID3.insert(s3);
    sgID3.insert(&sgID2); // the pointer to the address sgID2, and call the printArea() method in object ShapeGroupID 

    sgID3.printArea();

    delete r1; delete c1; delete s1; delete c2; delete s2;
    delete c3; delete s3;

    return 0;
}
