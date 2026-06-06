#include <iostream>
using namespace std;
int main() {
    cout << "Armstrong numbers between 1 and 500: ";
    for (int i = 1; i <= 500; ++i) {
        int num = i;
        int sum = 0;
while (num > 0) {
            int rem = num % 10;
            sum += (rem * rem * rem); // Cube the digit
            num /= 10;
        }
        if (sum == i) {
            cout << i << " ";
        }
    }
return 0;
}
