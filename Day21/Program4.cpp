#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); 
    for (char &c : str) {
        c = toupper(c);
    }
    cout << "Uppercase string: " << str << endl;

    return 0;
}
