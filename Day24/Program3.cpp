#include <iostream>
#include <string>
#include <sstream>
std::string findLongestWord(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string word;
    std::string longestWord = "";
    while (ss >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
return longestWord;
}

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);
std::string longest = findLongestWord(sentence);

    if (longest.empty()) {
        std::cout << "No words found." << std::endl;
    } else {
        std::cout << "The longest word is: \"" << longest << "\"" << std::endl;
        std::cout << "Length: " << longest.length() << std::endl;
    }
 return 0;
}
