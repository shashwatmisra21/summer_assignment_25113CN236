#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int lcm = (a > b) ? a : b;
    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            break;
        }
        lcm++;
    }

    cout << "LCM is: " << lcm << endl;

    return 0;
}
