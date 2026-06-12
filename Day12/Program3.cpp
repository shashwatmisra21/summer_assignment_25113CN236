#include <iostream>
#include <vector>
void printFibonacci(int n) {
    std::vector<int> fib(n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    std::cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        std::cout << fib[i] << " ";
    }
}
int main() {
    int terms;
    std::cout << "Enter number of terms (greater than 1): ";
    std::cin >> terms;
 printFibonacci(terms);
 return 0;
}
