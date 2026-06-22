#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
void printCharacterFrequency(const std::string& str) {
    std::unordered_map<char, int> freqMap;
    for (char ch : str) {
        freqMap[ch]++;
    }
    std::cout << "\nCharacter Frequencies:\n";
    for (const auto& pair : freqMap) {
        if (pair.first == ' ') {
            std::cout << "[Space]: " << pair.second << "\n";
        } else {
            std::cout << "'" << pair.first << "': " << pair.second << "\n";
        }
    }
}

int main() {
    std::string userInput;

    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    printCharacterFrequency(userInput);
return 0;
}
