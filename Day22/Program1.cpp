#include <iostream>
#include <string>
bool isPalindrome(const std::string& str) {
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        
        if (str[start] != str[end]) {
            return false;
        }
        start++; 
        end--;   
    }
    return true; 
}

int main() {
    std::string userInput;

    std::cout << "Enter a string: ";
    std::cin >> userInput;

    if (isPalindrome(userInput)) {
        std::cout << "\"" << userInput << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << userInput << "\" is not a palindrome." << std::endl;
    }
return 0;
}
