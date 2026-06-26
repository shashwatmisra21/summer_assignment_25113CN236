#include <iostream>
int main() {
    const int VOTING_AGE = 18;
    int userAge = 0;

    std::cout << "=================================\n";
    std::cout << "    VOTING ELIGIBILITY SYSTEM    \n";
    std::cout << "=================================\n";
    std::cout << "Enter your age: ";
    std::cin >> userAge;
    if (userAge < 0) {
        std::cout << "❌ Error: Age cannot be a negative number.\n";
    } 
    else if (userAge >= VOTING_AGE) {
        std::cout << "✅ You are eligible to vote!\n";
        std::cout << "Please register with your local election office.\n";
    } 
    else {
        int yearsLeft = VOTING_AGE - userAge;
        std::cout << "❌ You are not eligible to vote yet.\n";
        std::cout << "You will be eligible in " << yearsLeft << " year(s).\n";
    }

    return 0;
}
