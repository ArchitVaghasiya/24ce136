#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;
public:
    Account() {
        accountNumber = 0;
        holderName = "Default";
        balance = 0.0;
    }

    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    vector<Account> accounts;
    accounts.push_back(Account());
    accounts.push_back(Account(1001, "Alice", 500.0));
    accounts.push_back(Account(1002, "Bob", 1000.0));
    accounts.push_back(Account(1003, "Charlie", 750.0));

    accounts[1].deposit(200.0);
    accounts[2].withdraw(300.0);
    accounts[3].withdraw(800.0);
    accounts[0].deposit(100.0);

    for (int i = 0; i < accounts.size(); i++) {
        cout << "Account " << i + 1 << " Summary:" << endl;
        accounts[i].display();
        cout << endl;
    }

    return 0;
}

