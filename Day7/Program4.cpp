#include <iostream>
using namespace std;
void printReverse(int n) {
    if (n == 0) return; 
    cout << n % 10;
    printReverse(n / 10); 
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
 cout << "Reversed number is: ";
    if (num == 0) {
        cout << 0;
    } else {
        printReverse(num);
    }
    cout << endl;
     return 0;
}
