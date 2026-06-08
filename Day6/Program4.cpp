#include <iostream>
using namespace std;
int main() {
    double x;
    int n;
     cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
 double result = 1.0;
    for (int i = 0; i < n; i++) {
        result = result * x;
    }
 cout << x << "^" << n << " = " << result << endl;
return 0;
}
