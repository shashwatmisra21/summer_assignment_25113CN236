#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> commonChars(const std::vector<std::string>& words) {
    std::vector<int> minFreq(26, 100000); 
    for (const std::string& word : words) {
        std::vector<int> charCount(26, 0);
        for (char ch : word) {
            charCount[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            minFreq[i] = std::min(minFreq[i], charCount[i]);
        }
    }
    std::vector<std::string> result;
    for (int i = 0; i < 26; i++) {
        while (minFreq[i] > 0) {
            result.push_back(std::string(1, i + 'a'));
            minFreq[i]--;
        }
    }
    return result;
}

int main() {
    std::vector<std::string> words = {"bella", "label", "roller"};

    std::vector<std::string> common = commonChars(words);
    std::cout << "Common characters: ";
    for (const std::string& ch : common) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    return 0;
}
