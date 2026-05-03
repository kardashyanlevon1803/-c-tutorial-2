#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string number, double initialBalance) {
        accountNumber = number;
        balance = initialBalance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Not enough money!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            cout << "Balance: " << balance << endl;
        }
    }
};

int main() {
    BankAccount account("UA123456789", 1000.0);

    cout << "Account: " << account.getAccountNumber() << endl;
    cout << "Balance: " << account.getBalance() << endl;

    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0);

    return 0;
}