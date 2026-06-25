#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

int main() {
    std::vector<std::string> names = {"Rohit", "Aman", "Rahul", "Virat", "Smith"};
    std::sort(names.begin(), names.end());
    std::cout << "Names in alphabetical order:\n";
    for (const std::string& name : names) {
        std::cout << name << "\n";
    }
return 0;
}
