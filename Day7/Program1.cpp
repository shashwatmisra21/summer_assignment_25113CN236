#include <iostream>
using namespace std;
int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
cout << "Factorial is: " << factorial(num) << endl;
    return 0;
}
