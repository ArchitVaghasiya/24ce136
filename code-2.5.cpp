#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;
public:
    Loan() {
        loanID = 0;
        applicantName = "Default";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100);
        double numerator = loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths);
        double denominator = pow(1 + monthlyRate, tenureMonths) - 1;
        return denominator == 0 ? 0 : numerator / denominator;
    }

    void display() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: $" << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: $" << calculateEMI() << endl;
    }
};

int main() {
    vector<Loan> loans;
    loans.push_back(Loan());
    loans.push_back(Loan(201, "Alice", 50000, 7.5, 60));
    loans.push_back(Loan(202, "Bob", 75000, 6.8, 48));
    loans.push_back(Loan(203, "Charlie", 100000, 8.2, 72));

    for (int i = 0; i < loans.size(); i++) {
        cout << "Loan " << i + 1 << " Details:" << endl;
        loans[i].display();
        cout << endl;
    }

    return 0;
}

