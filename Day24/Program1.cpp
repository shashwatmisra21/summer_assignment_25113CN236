#include <iostream>
#include <string>
bool areRotations(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    std::string concatenated = str1 + str1;
    return (concatenated.find(str2) != std::string::npos);
}

int main() {
    std::string str1, str2;
 std::cout << "Enter the first string: ";
    std::cin >> str1;
std::cout << "Enter the second string: ";
    std::cin >> str2;

    if (areRotations(str1, str2)) {
        std::cout << "\"" << str2 << "\" is a rotation of \"" << str1 << "\"" << std::endl;
    } else {
        std::cout << "\"" << str2 << "\" is NOT a rotation of \"" << str1 << "\"" << std::endl;
    }
return 0;
}
