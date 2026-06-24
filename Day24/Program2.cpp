#include <iostream>
#include <string>
std::string compressString(const std::string& str) {
    int n = str.length();
    if (n == 0) return str;
    std::string compressed = "";
    int count = 1;
 for (int i = 0; i < n; i++) {
        if (i + 1 < n && str[i] == str[i + 1]) {
            count++;
        } else {
            compressed += str[i];
            compressed += std::to_string(count);
            count = 1;
        }
    }
    return (compressed.length() < str.length()) ? compressed : str;
}

int main() {
    std::string input;
    std::cout << "Enter a string to compress: ";
    std::cin >> input;

    std::string result = compressString(input);
    std::cout << "Result: " << result << std::endl;
return 0;
}
