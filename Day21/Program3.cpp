#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
int main() {
    string str;
    int vowels = 0;
    int consonants = 0;
    cout << "Enter a string: ";
    getline(cin, str); 
    for (char c : str) {
        if (isalpha(c)) {
            char low_c = tolower(c);
            if (low_c == 'a' || low_c == 'e' || low_c == 'i' || low_c == 'o' || low_c == 'u') {
                vowels++;
            } else {
            consonants++;
            }
        }
    }
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}
