#include <iostream>
using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    double balance;
    string history[MAX_TRANSACTIONS];
    int count;

public:
    BankAccount() {
        balance = 0;
        count = 0;
        history[count++] = "Account created with balance 0";
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit must be positive.\n";
            history[count++] = "Failed deposit: " + to_string(amount);
            return;
        }
        balance += amount;
        history[count++] = "Deposited: " + to_string(amount);
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal must be positive.\n";
            history[count++] = "Failed withdrawal: " + to_string(amount);
            return;
        }
        if (amount > balance) {
            cout << "Error: Not enough balance.\n";
            history[count++] = "Failed withdrawal (insufficient): " + to_string(amount);
            return;
        }
        balance -= amount;
        history[count++] = "Withdrew: " + to_string(amount);
    }

    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }

    void showHistory() {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < count; i++) {
            cout << history[i] << endl;
        }
    }
};

int main() {
    BankAccount account;

    account.deposit(500);
    account.withdraw(200);
    account.withdraw(400);
    account.deposit(-50);
    account.withdraw(100);

    account.showBalance();
    account.showHistory();

    return 0;
}
