#include <iostream>
#include <iomanip> 
int main() {
    double balance = 50000.00;
    int choice = 0;
    double amount = 0.0;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "====================================\n";
    std::cout << " WELCOME TO THE STATE BANK OF INDIA    \n";
    std::cout << "====================================\n";

    do {
        std::cout << "\n----- ATM MENU -----\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit ATM\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\n💰 Your current balance is: Rs. " << balance << "\n";
                break;

            case 2:
                std::cout << "\nEnter deposit amount: Rs. ";
                std::cin >> amount;
                
                if (amount <= 0) {
                    std::cout << "❌ Invalid amount. Deposit must be greater than zero.\n";
                } else {
                    balance += amount;
                    std::cout << "✅ Successfully deposited: Rs. " << amount << "\n";
                    std::cout << "New balance: Rs. " << balance << "\n";
                }
                break;

            case 3:
                std::cout << "\nEnter withdrawal amount: Rs. ";
                std::cin >> amount;

                if (amount <= 0) {
                    std::cout << "❌ Invalid amount. Withdrawal must be greater than zero.\n";
                } else if (amount > balance) {
                    std::cout << "❌ Transaction declined: Insufficient funds.\n";
                } else {
                    balance -= amount;
                    std::cout << "✅ Successfully withdrew: Rs. " << amount << "\n";
                    std::cout << "Remaining balance: Rs. " << balance << "\n";
                }
                break;

            case 4:
                std::cout << "\nThank you for choosing State Bank Of India. Goodbye!\n";
                break;

            default:
                std::cout << "❌ Invalid choice. Please select a valid option from the menu.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
