#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string num;
    std::cout << "Enter a number: ";
    std::cin >> num;
std::string reversedNum = num;
    std::reverse(reversedNum.begin(), reversedNum.end());

    if (num == reversedNum) {
        std::cout << "It is a palindrome!";
    } else {
        std::cout << "It is NOT a palindrome.";
    }
return 0;
}
