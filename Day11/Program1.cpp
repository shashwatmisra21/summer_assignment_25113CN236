#include <iostream>
int findSum(int num1, int num2) {
    return num1 + num2;
}
int main() {
    int a, b;
    std::cout << "Enter the first number: ";
    std::cin >> a;
std::cout << "Enter the second number: ";
    std::cin >> b;
    int totalSum = findSum(a, b);
    std::cout << "The sum of " << a << " and " << b << " is: " << totalSum << std::endl;
return 0;
}
