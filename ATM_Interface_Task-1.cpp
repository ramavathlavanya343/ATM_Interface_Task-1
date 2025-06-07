#include <iostream>


using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    ATM() {
        pin = 1234;      // Default PIN
        balance = 1000;  // Initial balance
    }

    bool authenticate(int enteredPin) {
        return enteredPin == pin;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- ATM Menu ---\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Change PIN\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: checkBalance(); break;
                case 2: deposit(); break;
                case 3: withdraw(); break;
                case 4: changePIN(); break;
                case 5: cout << "Thank you!\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (choice != 5);
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter deposit amount: ₹";
        cin >> amount;
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid amount!\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter withdraw amount: ₹";
        cin >> amount;
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance or invalid amount!\n";
    }

    void changePIN() {
        int newPin;
        cout << "Enter new PIN: ";
        cin >> newPin;
        pin = newPin;
        cout << "PIN successfully changed.\n";
    }
};

int main() {
    ATM userATM;
    int enteredPin, attempts = 0;

    while (attempts < 3) {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;

        if (userATM.authenticate(enteredPin)) {
            userATM.showMenu();
            break;
        } else {
            cout << "Incorrect PIN. Try again.\n";
            attempts++;
        }
    }

    if (attempts == 3)
        cout << "Card blocked due to 3 failed attempts.\n";

    return 0;
}

