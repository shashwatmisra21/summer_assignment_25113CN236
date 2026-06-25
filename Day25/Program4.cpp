#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

int main() {
    std::vector<std::string> words = {"elephant", "cat", "banana", "dog", "mango"};
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    std::cout << "Words sorted by length:\n";
    for (const std::string& word : words) {
        std::cout << word << " (" << word.length() << ")\n";
    }

    return 0;
}
