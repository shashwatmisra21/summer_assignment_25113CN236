#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number, originalNumber, sum = 0;
    cout << "Enter an integer: ";
    cin >> number;
    originalNumber = number;
    number = abs(number);
    while (number > 0) {
        sum += number % 10; 
        number /= 10;     
    }

    cout << "The sum of the digits of " << originalNumber << " is: " << sum << endl;

    return 0;
}
