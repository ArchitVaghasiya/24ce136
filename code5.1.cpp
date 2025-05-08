#include <iostream>
#include <string>

class Calculator {
private:
    static const int MAX_RESULTS = 100;
    std::string results[MAX_RESULTS];
    int count;

public:
    Calculator() : count(0) {}

    int add(int a, int b) {
        int result = a + b;
        storeResult(a, b, result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        storeResult(a, b, result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        storeResult(a, b, result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        storeResult(a, b, result);
        return result;
    }

    template<typename T1, typename T2, typename T3>
    void storeResult(T1 a, T2 b, T3 result) {
        if (count < MAX_RESULTS) {
            results[count++] = "Addition of " + std::to_string(a) + " and " +
                               std::to_string(b) + " = " + std::to_string(result);
        } else {
            std::cout << "Result storage limit reached!" << std::endl;
        }
    }

    void displayResults() const {
        std::cout << "\n--- Calculation Results ---\n";
        for (int i = 0; i < count; ++i) {
            std::cout << results[i] << std::endl;
        }
    }
};

int main() {
    Calculator calc;
    calc.add(10, 5);
    calc.add(3.2, 4.8);
    calc.add(7, 2.5);
    calc.add(1.5, 4);
    calc.displayResults();
    return 0;
}
