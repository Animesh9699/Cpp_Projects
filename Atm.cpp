#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    int pin = 1234; // Default PIN
    double balance = 1000.00;

public:
    void authenticate() {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;
        if (enteredPin != pin) {
            cout << "Incorrect PIN!" << endl;
            exit(0);
        }
    }

    void displayMenu() {
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Cash" << endl;
        cout << "3. Deposit Cash" << endl;
        cout << "4. Exit" << endl;
    }

    void checkBalance() {
        cout << "Your balance is: $" << balance << endl;
    }

    void withdrawCash() {
        double amount;
        cout << "Enter amount to withdraw: $";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        }
    }

    void depositCash() {
        double amount;
        cout << "Enter amount to deposit: $";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful! New balance: $" << balance << endl;
    }

    void run() {
        authenticate();
        int choice;
        while (true) {
            displayMenu();
            cout << "Select an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    withdrawCash();
                    break;
                case 3:
                    depositCash();
                    break;
                case 4:
                    cout << "Exiting... Thank you!" << endl;
                    exit(0);
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}
