#include <iostream>
using namespace std;
int main() {
    int num, temp, digit;
    int sum = 0;
    int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
cout << "Enter a number: ";
    cin >> num;
temp = num;
    while (temp > 0) {
        digit = temp % 10; 
        sum += fact[digit]; 
        temp = temp / 10;  
    }
    if (sum == num && num > 0) {
        cout << num << " strong number." << endl;
    } else {
        cout << num << " not a strong number." << endl;
    }
return 0;
}
