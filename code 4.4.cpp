#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TRANSACTIONS = 100;
class BankAccount {
protected:
    int accountNumber;
    double balance;
    double transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

public:
    BankAccount(int accNo = 0, double bal = 0.0) {
        accountNumber = accNo;
        balance = bal;
        transactionCount = 0;
    }

    virtual ~BankAccount() {
        cout << "Account " << accountNumber << " closed.\n";
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction(amount);
            cout << "Deposited: $" << amount << ", New Balance: $" << balance << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            addTransaction(-amount);
            cout << "Withdrew: $" << amount << ", New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    void addTransaction(double amount) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = amount;
        }
    }

    void undoLastTransaction() {
        if (transactionCount > 0) {
            double last = transactionHistory[--transactionCount];
            balance -= last;
            cout << "Last transaction of $" << last << " undone. New Balance: $" << balance << endl;
        } else {
            cout << "No transaction to undo.\n";
        }
    }

    virtual void display() const {
        cout << "Account No: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate)
        : BankAccount(accNo, bal), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * (interestRate / 100.0);
        deposit(interest);
        cout << "Interest of $" << interest << " applied at rate " << interestRate << "%\n";
    }

    void display() const override {
        BankAccount::display();
        cout << "Account Type: Savings, Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double bal, double overdraft)
        : BankAccount(accNo, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            balance -= amount;
            addTransaction(-amount);
            cout << "Withdrew: $" << amount << ", New Balance: $" << balance << endl;
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }

    void display() const override {
        BankAccount::display();
        cout << "Account Type: Current, Overdraft Limit: $" << overdraftLimit << "\n";
    }
};

void bankingSimulation() {
    SavingsAccount sav(1001, 5000, 5.0);
    CurrentAccount cur(2001, 1000, 500);
    sav.display();
    sav.deposit(1000);
    sav.withdraw(2000);
    sav.applyInterest();
    sav.undoLastTransaction();
    sav.display();
    cur.display();
    cur.deposit(500);
    cur.withdraw(1800);
    cur.withdraw(100);
    cur.undoLastTransaction();
    cur.display();
}

int main() {
    bankingSimulation();
    return 0;
}
