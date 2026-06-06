#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter position (n): ";
    cin >> n;
int a = 0, b = 1, c;
    for (int i = 1; i < n; ++i) {
        c = a + b; 
        a = b;     
        b = c;    
    }
cout << "The result is: " << a << endl;
return 0;
}
