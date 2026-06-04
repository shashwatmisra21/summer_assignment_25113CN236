#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    long long product = 1;

    cout << "Enter an integer: ";
    cin >> number;
    if (number == 0) {
        product = 0;
    } else {
    
        int temp = abs(number); 

        while (temp > 0) {
            int last_digit = temp % 10; 
            product *= last_digit;      
            temp /= 10;                 
        }
    }

    cout << "The product of the digits is: " << product << endl;

    return 0;
}
