#include <iostream>
bool isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) sum += i;
    }
    return sum == num;
}int main() {
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    std::cout << n << (isPerfect(n) ? " is perfect." : " is not perfect.");
    return 0;
}
