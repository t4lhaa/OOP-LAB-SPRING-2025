#include <iostream>
using namespace std;

class Wallet{
private:
    string name;
    double balance;
    string statement[50];
    int count;

public:
    Wallet(string name, double initialBalance)
    {
        name = name;
        balance = initialBalance;
        count = 0;
        statements("Account created with balance: RS " + to_string(initialBalance));
    }

    void statements(string transaction)
    {
        if (count < 50)
        {
            statement[count] = transaction;
            count++;
        }
    }

    void add(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            statements("Amount added: RS " + to_string(amount));
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance!\n";
            return;
        }
        balance = balance - amount;
        statements("Amount withdrawed: RS " + to_string(amount));

        if (balance < 100)
        {
            cout << "Low balance! Only RS " << balance << " left.\n";
        }
    }

    void displayStatement()
    {
        cout << "\nSTransaction History of " << name << ":\n";
        for (int i = 0; i < count; i++)
        {
            cout << "-> " << statement[i] << endl;
        }
        cout << "Current Balance: RS " << balance << "\n";
    }
};

int main()
{
    string name;
    double initialBalance;

    cout << "Enter wallet owner's name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Wallet myWallet(name, initialBalance);

    int choice;
    double amount;

    do
    {
        cout << "1. Add Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Show Transaction History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to add: ";
            cin >> amount;
            myWallet.add(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myWallet.withdraw(amount);
            break;
        case 3:
            myWallet.displayStatement();
            break;
        case 4:
            cout << "Good Bye!";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
