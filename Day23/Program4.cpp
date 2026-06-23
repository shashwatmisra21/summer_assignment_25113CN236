#include <iostream>
#include <string>
#include <vector>
char getMaxOccurringChar(const std::string& s) {
    std::vector<int> freq(256, 0);
    for (char ch : s) {
        freq[static_cast<unsigned char>(ch)]++;
    }
    int maxCount = 0;
    char maxChar = '\0';

    for (char ch : s) {
        int currentCount = freq[static_cast<unsigned char>(ch)];
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxChar = ch;
        }
    }

    return maxChar;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    char result = getMaxOccurringChar(input);
    
    if (result != '\0') {
        std::cout << "Maximum occurring character is: '" << result << "'\n";
    }

    return 0;
}
