#include <iostream>
using namespace std;
int main() {
    int rows = 5;
 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            cout << " ";
        }
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch;
        }
        for (char ch = 'A' + i - 1; ch >= 'A'; ch--) {
            cout << ch;
        }
cout << endl;
    }
return 0;
}
