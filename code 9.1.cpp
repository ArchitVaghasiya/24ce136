#include <iostream>

using namespace std;

int main() {
    double loanAmount, income;

    cout << "Enter loan amount: ";
    cin >> loanAmount;

    if (cin.fail()) {
        cout << "Invalid input! Please enter a number for loan amount." << endl;
        return 1;
    }

    cout << "Enter annual income: ";
    cin >> income;

    if (cin.fail()) {
        cout << "Invalid input! Please enter a number for income." << endl;
        return 1;
    }

    if (income == 0) {
        cout << "Income cannot be zero. Division by zero is not allowed." << endl;
        return 1;
    }

    double ratio = loanAmount / income;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    return 0;
}
