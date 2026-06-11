#include <iostream>
using namespace std;
int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
int t1 = 0, t2 = 1, nextTerm;
cout << "Fibonacci Series: ";
for (int i = 1; i <= terms; ++i) {
        cout << t1 << " "; 
        nextTerm = t1 + t2; 
        t1 = t2;            
        t2 = nextTerm;      
    }
     return 0;
}
