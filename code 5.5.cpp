#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
    virtual void show() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() override {
        return length * width;
    }

    void show() override {
        cout << "Rectangle Area: " << Area() << endl;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float Area() override {
        return M_PI * radius * radius;
    }

    void show() override {
        cout << "Circle Area: " << Area() << endl;
    }
};

int main() {
    const int SIZE = 5;
    Shape* shapes[SIZE];
    int count = 0;

    shapes[count++] = new Rectangle(5, 3);
    shapes[count++] = new Circle(4);

    cout << "Calculating Areas:\n";
    for (int i = 0; i < count; ++i) {
        shapes[i]->show();
    }

    for (int i = 0; i < count; ++i) {
        delete shapes[i];
    }

    return 0;
}
