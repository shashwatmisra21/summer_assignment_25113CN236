#include <iostream>
using namespace std;
int findFactorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
cout << "Factorial is: " << findFactorial(num) << endl;
    return 0;
}
