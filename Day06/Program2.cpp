#include <iostream>
#include <string>
using namespace std;
int main() {
    string binaryStr;
    cout << "Enter a binary number: ";
    cin >> binaryStr;
    int decimalNum = stoi(binaryStr, nullptr, 2);
cout << "Decimal equivalent: " << decimalNum << endl;
return 0;
}
