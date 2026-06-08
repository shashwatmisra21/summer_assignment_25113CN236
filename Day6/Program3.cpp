#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int totalSetBits = __builtin_popcount(num);
cout << "Number of set bits (1s): " << totalSetBits << endl;
return 0;
}
