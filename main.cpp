#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// abstract class
class Figure {
public:
    virtual void draw() = 0;  
    virtual double area() = 0;      
    virtual ~Figure() {}              
};

// inheritance
class Circle : public Figure {

private:
    double radius; 

public:
    Circle(double r) : radius(r) {}  

    // incapsulations
    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }

    // polymorphism
    void draw() override {
        cout << "Drawing a circle with the radius: " << radius << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;  
    }

    ~Circle() {
        cout << "Destructor Circle!" << endl;
    }
};

// inheritance & polymorphism
class Rectangle : public Figure {

private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const {
        return length;
    }

    void setLength(double l) {
        length = l;
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double w) {
        width = w;
    }

    void draw() override {
        cout << "Drawing a rectangle with the length: " << length << " and width: " << width << endl;
    }

    double area() override {
        return length * width;  
    }

    ~Rectangle() {
        cout << "Destructor Rectangle!" << endl;
    }
};

// incapsulation and abstraction
class FigureActions {

private:
    vector<Figure*> forme;  

public:
    void addFigure(Figure* f) {
        forme.push_back(f);
    }

    void showFigureArea() {
        for (Figure* f : forme) {
            cout << "Figure area is: " << f->area() << endl;
        }
    }

    void drawFigire() {
        for (Figure* f : forme) {
            f->draw();
        }
    }

    ~FigureActions() {
        for (Figure* f : forme) {
            delete f;
        }
    }
};

int main() {
    Circle* circle = new Circle(5.0);
    Rectangle* rectangle = new Rectangle(4.0, 6.0);

    FigureActions action;

    action.addFigure(circle);
    action.addFigure(rectangle);
    action.drawFigire();
    action.showFigureArea();

    return 0;
}
