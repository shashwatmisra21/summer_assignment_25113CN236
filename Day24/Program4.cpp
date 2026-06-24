#include <iostream>
#include <string>
#include <unordered_set>
std::string removeDuplicates(const std::string& str) {
    std::string result = "";
    std::unordered_set<char> seen;

    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);  
            result += ch;  
        }
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::string orderedUnique = removeDuplicates(input);
    std::cout << "Result after removing duplicates: " << orderedUnique << std::endl;
 return 0;
}
