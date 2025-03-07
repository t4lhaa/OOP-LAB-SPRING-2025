
#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    float balance;

public:
    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    void displayDetails()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account
{
protected:
    float interestRate;

public:
    SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}
    void displayDetails()
    {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account
{
protected:
    float overDraftLimit;

public:
    CheckingAccount(int accountNumber, float balance, float overDraftLimit) : Account(accountNumber, balance), overDraftLimit(overDraftLimit) {}
    void displayDetails()
    {
        Account::displayDetails();
        cout << "Over Draft Limit: $" << overDraftLimit << endl;
    }
};

int main()
{
    SavingsAccount s(834, 100000, 30);
    s.displayDetails();

    cout << endl;
    CheckingAccount c(834, 500000, 10000);
    c.displayDetails();
}
