#include <iostream>
#include <string>
#include <vector>
char findFirstRepeating(const std::string& s) {
    std::vector<bool> seen(256, false);
    for (char ch : s) {
        unsigned char index = static_cast<unsigned char>(ch);
        if (seen[index]) {
            return ch;
        }
        seen[index] = true;
    }
    return '\0';
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    char result = findFirstRepeating(input);

    if (result != '\0') {
        std::cout << "The first repeating character is: '" << result << "'\n";
    } else {
        std::cout << "No repeating characters found.\n";
    }

    return 0;
}
