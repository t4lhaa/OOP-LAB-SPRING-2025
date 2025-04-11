#include <iostream>
using namespace std;

class Account
{
    int accNum;
    double balance;

    friend class Manager;

    friend void transferFunds(Account &acc1, Account &acc2, double amount);

public:
    Account(int accNum, double balance) : accNum(accNum), balance(balance) {}
};
class Manager
{

public:
    void displayDetails(Account &Acc) const
    {
        cout << "Details: " << endl;
        cout << "Account Number: " << Acc.accNum << endl;
        cout << "Total Balance: " << Acc.balance << endl;
    }

    void withdraw(Account &Acc, double amount)
    {
        Acc.balance -= amount;
        cout << "Amount : " << amount << " withdrawn successfully!" << endl;
    }

    void deposit(Account &Acc, double amount)
    {
        Acc.balance -= amount;
        cout << "Amount : " << amount << " withdrawn successfully!" << endl;
    }
};

void transferFunds(Account &acc1, Account &acc2, double amount)
{
    if (amount > 0 && amount <= acc1.balance)
    {
        acc1.balance -= amount;
        acc2.balance += amount;
        cout << "Amount: " << amount << " trasferred from Account  " << acc1.accNum << " to Account  " << acc2.accNum << endl;
    }
    else
    {
        cout << "Insufficient Amount!!!!!!!" << endl;
    }
}

int main()

{
    Manager Talha;

    Account JazzCash(45461464, 2000);
    Talha.displayDetails(JazzCash);
    Talha.withdraw(JazzCash, 1000);
    
    Account EasyPaisa(484649, 3000);
    Talha.displayDetails(EasyPaisa);
    Talha.deposit(EasyPaisa, 2000);

    transferFunds(JazzCash, EasyPaisa, 1000);

    Talha.displayDetails(JazzCash);
    Talha.displayDetails(EasyPaisa);

    return 0;
}
