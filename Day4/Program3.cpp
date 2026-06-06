#include <iostream>
using namespace std;
int main() {
    int num, originalnum, rem, sum = 0;
cout << "Enter a 3-digit number: ";
    cin >> num;
originalnum = num;
    while (num > 0) {
        rem = num % 10;          
        sum += (rem * rem * rem); 
        num /= 10;               
    }
    if (sum == originalnum)
        cout << originalnum << " is an Armstrong number." << endl;
    else
        cout << originalnum << " is not an Armstrong number." << endl;

    return 0;
}
