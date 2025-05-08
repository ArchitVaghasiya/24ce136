#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }
};

class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}

    double calculateArea() const {
        return M_PI * radius * radius;
    }

    void display() const {
        cout << "Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};

void staticHandling() {
    const int SIZE = 3;
    Circle circles[SIZE] = { Circle(2.5), Circle(3.0), Circle(4.1) };

    cout << "\n--- Static Handling ---" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Circle " << i + 1 << ": ";
        circles[i].display();
    }
}

void dynamicHandling() {
    int size;
    cout << "\nEnter the number of circles: ";
    cin >> size;

    Circle** circles = new Circle*[size];

    for (int i = 0; i < size; ++i) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles[i] = new Circle(r);
    }

    cout << "\n--- Dynamic Handling ---" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Circle " << i + 1 << ": ";
        circles[i]->display();
    }

    for (int i = 0; i < size; ++i) {
        delete circles[i];
    }
    delete[] circles;
}

int main() {
    staticHandling();
    dynamicHandling();

    return 0;
}
