#include <iostream>

class Point {
private:
    float x, y;

public:
    Point(float xCoord = 0, float yCoord = 0) {
        x = xCoord;
        y = yCoord;
    }

    Point* moveBy(float dx, float dy) {
        x += dx;
        y += dy;
        return this;
    }

    void print() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
};

int main() {
    Point* p = new Point(1.0f, 2.0f);

    std::cout << "Original: ";
    p->print();

    p->moveBy(3.5f, -1.2f)->moveBy(-2.0f, 4.0f);
    std::cout << "After chained move: ";
    p->print();

    delete p;

    return 0;
}
