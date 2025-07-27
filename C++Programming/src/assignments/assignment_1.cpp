
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string shapeName) : name(shapeName) {
        cout << "Shape Constructor called for: " << name << endl;
    }


    virtual void calculateArea() const = 0;


    virtual ~Shape() {
        cout << "Shape Destructor called for: " << name << endl;
    }
};


class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) : Shape("Rectangle"), length(l), breadth(b) {}

    void calculateArea() const override {
        double area = length * breadth;
        cout << "Area of Rectangle (" << length << " x " << breadth << "): " << area << endl;
    }

    ~Rectangle() {
        cout << "Rectangle Destructor\n";
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void calculateArea() const override {
        double area = M_PI * radius * radius;
        cout << "Area of Circle (radius " << radius << "): " << area << endl;
    }

    ~Circle() {
        cout << "Circle Destructor\n";
    }
};


class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}

    void calculateArea() const override {
        double area = 0.5 * base * height;
        cout << "Area of Triangle (" << base << " x " << height << " / 2): " << area << endl;
    }

    ~Triangle() {
        cout << "Triangle Destructor\n";
    }
};

int main() {

    const int size = 3;
    Shape* shapes[size];


    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(4.0);
    shapes[2] = new Triangle(6.0, 2.5);

    cout << "\n--- Calculating Areas ---\n";
    for (int i = 0; i < size; ++i) {
        shapes[i]->calculateArea();
    }


    cout << "\n--- Cleaning up ---\n";
    for (int i = 0; i < size; ++i) {
        delete shapes[i];
    }

    return 0;
}




