#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter an integer to print its multiplication table: ";
    cin >> num;

    cout << "\nMultiplication Table for " << num << ":\n";
    cout << "-----------------------------\n";
    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }

    return 0;
}
