#include <iostream>
using namespace std;
int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;
long long divisor = 2;
    while (num > 1) {
        if (num % divisor == 0) {
            num /= divisor;
        } else {
            divisor++; 
        }
    }
    cout << "The largest prime factor is: " << divisor << endl;
}
