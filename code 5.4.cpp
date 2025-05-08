#include <iostream>
using namespace std;

class Temperature {
public:
    virtual void show() const = 0;
    virtual float getValue() const = 0;
    virtual ~Temperature() {}
};

class Celsius : public Temperature {
    float temp;
public:
    Celsius(float t = 0) : temp(t) {}

    operator class Fahrenheit();

    bool operator==(const Celsius& other) const {
        return temp == other.temp;
    }

    float getValue() const override {
        return temp;
    }

    void show() const override {
        cout << temp << " °C" << endl;
    }
};

class Fahrenheit : public Temperature {
    float temp;
public:
    Fahrenheit(float t = 32) : temp(t) {}

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(const Fahrenheit& other) const {
        return temp == other.temp;
    }

    float getValue() const override {
        return temp;
    }

    void show() const override {
        cout << temp << " °F" << endl;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
    const int SIZE = 5;
    Temperature* conversions[SIZE];
    int index = 0;

    Celsius c1(25);
    Fahrenheit f1 = c1;
    conversions[index++] = new Fahrenheit(f1);

    Fahrenheit f2(98.6);
    Celsius c2 = f2;
    conversions[index++] = new Celsius(c2);

    cout << "Converted Temperatures:\n";
    for (int i = 0; i < index; ++i) {
        conversions[i]->show();
    }

    cout << "\nEquality Check:\n";
    if (c1 == Celsius(f2)) {
        cout << "25°C is equal to 98.6°F\n";
    } else {
        cout << "25°C is not equal to 98.6°F\n";
    }

    for (int i = 0; i < index; ++i) {
        delete conversions[i];
    }

    return 0;
}
