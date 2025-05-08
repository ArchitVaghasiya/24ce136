#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor\n";
    }

    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
private:
    int* buffer;

public:
    Derived() {
        buffer = new int[5];
        std::cout << "Derived constructor: Allocated buffer\n";
    }

    ~Derived() {
        delete[] buffer;
        std::cout << "Derived destructor: Deallocated buffer\n";
    }
};

int main() {
    Base* ptr = new Derived();

    delete ptr;
    return 0;
}
