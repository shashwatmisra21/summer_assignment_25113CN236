#include <iostream>
using namespace std;

int main() {
    int num, originalNum, remainder;
    int reversedNum = 0;

    cout << "Enter an integer: ";
    cin >> num;
    originalNum = num;
    if (num < 0) {
        cout << originalNum << " is not a palindrome number." << endl;
        return 0;
    }
    while (num != 0) {
        remainder = num % 10;                     
        reversedNum = (reversedNum * 10) + remainder; 
        num /= 10;                                
    }
    if (originalNum == reversedNum) {
        cout << originalNum << " is a palindrome number." << endl;
    } else {
        cout << originalNum << " is not a palindrome number." << endl;
    }

    return 0;
}
