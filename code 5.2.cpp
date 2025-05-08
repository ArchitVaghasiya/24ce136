#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Friend functions for input and output
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

// Output format: a + bi or a - bi
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";
    return out;
}

// Input format: real imag (space-separated)
istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

// Batch operations on a vector of Complex numbers
Complex sumOfComplexNumbers(const vector<Complex>& vec) {
    Complex sum;
    for (const auto& num : vec) {
        sum = sum + num;
    }
    return sum;
}

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Batch operation
    int n;
    cout << "\nEnter number of complex numbers for batch addition: ";
    cin >> n;
    vector<Complex> compList(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nComplex number " << i + 1 << ":\n";
        cin >> compList[i];
    }

    Complex batchSum = sumOfComplexNumbers(compList);
    cout << "\nSum of all complex numbers: " << batchSum << endl;

    return 0;
}
