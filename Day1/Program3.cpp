#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    // Factorial is not defined for negative numbers
    if (n < 0) {
        cout << "Error! Factorial of a negative number does not exist." << endl;
    } else {
        // Loop to multiply numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        cout << "Factorial of " << n << " = " << factorial << endl;
    }

    return 0;
}
