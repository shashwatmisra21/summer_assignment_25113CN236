#include <iostream>
#include <string>
#include <sstream>
int countWords(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string word;
    int wordCount = 0;
    while (ss >> word) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    std::string userSentence;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, userSentence);

    int totalWords = countWords(userSentence);
    std::cout << "Total word count: " << totalWords << std::endl;

    return 0;
}
