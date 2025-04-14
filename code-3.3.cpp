#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;
    static int totalAccounts;
public:
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
        totalAccounts++;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    bool transfer(Account& toAccount, double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            toAccount.balance += amount;
            return true;
        }
        return false;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

int main() {
    vector<Account> accounts;
    accounts.push_back(Account(101, "Akshar", 1000));
    accounts.push_back(Account(102, "Rudra", 1500));
    accounts.push_back(Account(103, "Param", 800));

    accounts[0].transfer(accounts[1], 300);
    accounts[2].transfer(accounts[0], 200);

    for (int i = 0; i < accounts.size(); i++) {
        cout << "Account " << i + 1 << " Details:" << endl;
        accounts[i].display();
        cout << endl;
    }

    cout << "Total Accounts Created: " << Account::getTotalAccounts() << endl;

    return 0;
}

