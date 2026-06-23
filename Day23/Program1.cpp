#include <iostream>
#include <string>
#include <vector>
char findFirstNonRepeating(const std::string& s) {
    std::vector<int> freq(256, 0);
    for (char ch : s) {
        freq[static_cast<unsigned char>(ch)]++;
    }
    for (char ch : s) {
        if (freq[static_cast<unsigned char>(ch)] == 1) {
            return ch; 
        }
    }
    return '\0'; 
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    char result = findFirstNonRepeating(input);

    if (result != '\0') {
        std::cout << "The first non-repeating character is: '" << result << "'\n";
    } else {
        std::cout << "All characters are repeating.\n";
    }

    return 0;
}
