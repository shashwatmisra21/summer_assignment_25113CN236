#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string accNum, std::string name, double initialDeposit)
        : accountNumber(accNum), accountHolderName(name), balance(initialDeposit) {}
    std::string getAccountNumber() const { return accountNumber; }
    std::string getHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited " << std::fixed << std::setprecision(2) << amount << "\n";
            std::cout << "Current Balance: " << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "Transaction declined: Insufficient funds!\n";
            return false;
        }
        balance -= amount;
        std::cout << "Successfully withdrew " << std::fixed << std::setprecision(2) << amount << "\n";
        std::cout << "Remaining Balance: " << balance << "\n";
        return true;
    }

    // Display details
    void displayAccountInfo() const {
        std::cout << std::left << std::setw(15) << accountNumber 
                  << std::setw(25) << accountHolderName 
                  << std::fixed << std::setprecision(2) << balance << "\n";
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;
    auto findAccount(const std::string& accNum) {
        return std::find_if(accounts.begin(), accounts.end(), [&accNum](const BankAccount& acc) {
            return acc.getAccountNumber() == accNum;
        });
    }
    std::string generateAccountNumber() {
        std::string accNum;
        do {
            accNum = std::to_string(10000 + rand() % 90000);
        } while (findAccount(accNum) != accounts.end()); 
        return accNum;
    }

public:
    void createAccount() {
        std::string name;
        double initialDeposit;

        std::cout << "\nEnter Account Holder Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter Initial Deposit Amount (Minimum 500): ";
        while (!(std::cin >> initialDeposit) || initialDeposit < 500) {
            std::cout << "Invalid input. Minimum initial deposit must be 500: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        std::string accNum = generateAccountNumber();
        accounts.emplace_back(accNum, name, initialDeposit);

        std::cout << "\nAccount Created Successfully!\n";
        std::cout << "Holder Name   : " << name << "\n";
        std::cout << "Account Number: " << accNum << "\n";
        std::cout << "Balance       : " << initialDeposit << "\n";
    }
    void depositMoney() {
        std::string accNum;
        double amount;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        auto it = findAccount(accNum);
        if (it != accounts.end()) {
            std::cout << "Enter Amount to Deposit: ";
            std::cin >> amount;
            it->deposit(amount);
        } else {
            std::cout << "Error: Account not found!\n";
        }
    }
    void withdrawMoney() {
        std::string accNum;
        double amount;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        auto it = findAccount(accNum);
        if (it != accounts.end()) {
            std::cout << "Enter Amount to Withdraw: ";
            std::cin >> amount;
            it->withdraw(amount);
        } else {
            std::cout << "Error: Account not found!\n";
        }
    }
    void checkBalance() {
        std::string accNum;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        auto it = findAccount(accNum);
        if (it != accounts.end()) {
            std::cout << "\n--- Account Summary ---\n";
            std::cout << "Account Holder: " << it->getHolderName() << "\n";
            std::cout << "Account Number: " << it->getAccountNumber() << "\n";
            std::cout << "Current Balance: " << std::fixed << std::setprecision(2) << it->getBalance() << "\n";
        } else {
            std::cout << "Error: Account not found!\n";
        }
    }
    void displayAllAccounts() const {
        if (accounts.empty()) {
            std::cout << "\nNo active bank accounts found.\n";
            return;
        }

        std::cout << "\n--------------------------------------------------------\n";
        std::cout << std::left << std::setw(15) << "Account No." 
                  << std::setw(25) << "Holder Name" 
                  << "Balance\n";
        std::cout << "--------------------------------------------------------\n";
        for (const auto& acc : accounts) {
            acc.displayAccountInfo();
        }
        std::cout << "--------------------------------------------------------\n";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    Bank dynamicBank;
    int choice;

    do {
        std::cout << "\n====== Core Banking Console ======\n";
        std::cout << "1. Open New Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Balance Enquiry\n";
        std::cout << "5. Display All Accounts\n";
        std::cout << "6. Exit Application\n";
        std::cout << "==================================\n";
        std::cout << "Enter choice (1-6): ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please choose an option between 1 and 6: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        switch (choice) {
            case 1: dynamicBank.createAccount(); break;
            case 2: dynamicBank.depositMoney(); break;
            case 3: dynamicBank.withdrawMoney(); break;
            case 4: dynamicBank.checkBalance(); break;
            case 5: dynamicBank.displayAllAccounts(); break;
            case 6: std::cout << "\nLogging off.\n"; break;
            default: std::cout << "Selection out of bounds.\n";
        }
    } while (choice != 6);

    return 0;
}
