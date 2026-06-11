#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;
    cout << "Binary: " << bitset<8>(decimalNum) << endl;
return 0;
}
