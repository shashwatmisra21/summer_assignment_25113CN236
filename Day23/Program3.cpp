#include <iostream>
#include <string>
#include <algorithm> 

bool isAnagram(std::string s1, std::string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter first string: ";
    std::cin >> str1;
    std::cout << "Enter second string: ";
    std::cin >> str2;

    if (isAnagram(str1, str2)) {
        std::cout << "They are anagrams.\n";
    } else {
        std::cout << "They are not anagrams.\n";
    }

    return 0;
}
