//Design a simple class BankAccount to represent a bank account. It should have
//the following:
//Attributes:
//o Account holder's name, account number, and balance.
//Methods:
//o deposit(amount): to add money to the account.
//o withdraw(amount): to deduct money from the account if sufficient balance
//exists. Otherwise, print an error message.
//o display_balance() to show the current balance.
//Requirements:
//o Demonstrate object-oriented principles: encapsulation and abstraction.
//o Test the class by creating multiple accounts and performing operations.
#include<iostream>
#include<iomanip>
using namespace std;
class BankAccount
{
    int AccountNum;
    char HolderName[25];
    float Balance;
    float Diposit, Withdraw;

    public:
        void AccountHolderData()
        {

           cout << "Enter your  AccountNum : ";
           cin >>  AccountNum;
           cout << "Enetr your HolderName: ";
           cin >> HolderName;
            cout << "Enetr your Balance: ";
           cin >> Balance;
        }

        void DisplayHoldersData()
        {
            cout << "Holder's name : " << HolderName << "\n" << "Account Number : " << AccountNum << "\n" << "Your balance : " << fixed << setprecision(10) <<Balance << "\n";
        }

        void D_W()
        {
            cout << "Enter the ammount of Diposit :";
            cin  >> Diposit;
            cout << "Enter the ammount of Withdraw :";
            cin >> Withdraw;
             Balance = Balance+Diposit-Withdraw;
        }

        void DisplayBalance()
        {
            cout << Balance;
        }
}s1;
int main()
{
    s1.AccountHolderData();
    s1.DisplayHoldersData();
    s1.D_W();
    s1.DisplayBalance();
    return 0;
}
