#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point current(2, 3);
    Point backup;

    cout << "Initial Point: ";
    current.print();

    backup = current;

    Point toAdd(1, 1);
    current = current + toAdd;
    cout << "After adding (1, 1): ";
    current.print();

    current = backup;
    cout << "After undo: ";
    current.print();

    backup = current;

    current = -current;
    cout << "After negation: ";
    current.print();

    current = backup;
    cout << "After undo: ";
    current.print();

    return 0;
}
