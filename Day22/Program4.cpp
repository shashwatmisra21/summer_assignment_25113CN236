#include <iostream>
#include <string>
#include <algorithm>
void removeSpaces(std::string& str) {
    auto newEnd = std::remove(str.begin(), str.end(), ' ');
    str.erase(newEnd, str.end());
}

int main() {
    std::string userInput;

    std::cout << "Enter a string with spaces: ";
    std::getline(std::cin, userInput);

    removeSpaces(userInput);

    std::cout << "String after removing spaces: " << userInput << std::endl;

    return 0;
}
