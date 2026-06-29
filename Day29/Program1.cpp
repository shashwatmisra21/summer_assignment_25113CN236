#include <iostream>
using namespace std;
void displayMenu();
void performCalculation(int choice);
int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        if (choice >= 1 && choice <= 4) {
            performCalculation(choice);
        } else if (choice == 5) {
            cout << "\nExiting the calculator. Goodbye!\n";
        } else {
            cout << "\nInvalid choice! Please select a valid option from the menu.\n";
        }

    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\n===============================\n";
    cout << "     MENU-DRIVEN CALCULATOR    \n";
    cout << "===============================\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "===============================\n";
}
void performCalculation(int choice) {
    double num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            cout << "\nResult: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
            break;
        case 2:
            cout << "\nResult: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
            break;
        case 3:
            cout << "\nResult: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
            break;
        case 4:
            if (num2 != 0) {
                cout << "\nResult: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
            } else {
                cout << "\nError: Division by zero is not allowed!\n";
            }
            break;
        default:
            cout << "\nAn unexpected error occurred.\n";
    }
}
