#include <iostream>
using namespace std;
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0; 
    }
    return 1; 
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
if (isPrime(num)) cout << num << " is prime.";
    else cout << num << " is not prime.";
return 0;
}
