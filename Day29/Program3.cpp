#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void displayMenu();
void concatenateStrings();
void reverseString();
void checkPalindrome();
void findSubstring();
void changeCase();

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                findSubstring();
                break;
            case 5:
                changeCase();
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
void displayMenu() {
    cout << "\n====================================\n";
    cout << "   STRING OPERATIONS MENU SYSTEM    \n";
    cout << "====================================\n";
    cout << "1. Concatenate Two Strings\n";
    cout << "2. Reverse a String\n";
    cout << "3. Check if Palindrome\n";
    cout << "4. Find Substring Occurrence\n";
    cout << "5. Convert Case (Upper/Lower)\n";
    cout << "6. Exit\n";
    cout << "====================================\n";
}
void concatenateStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    string result = str1 + str2;
    cout << "\nConcatenated Result: " << result << "\n";
}
void reverseString() {
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());

    cout << "\nOriginal String: " << str << "\n";
    cout << "Reversed String: " << reversedStr << "\n";
}
void checkPalindrome() {
    string str;
    cout << "Enter a string to check for palindrome: ";
    getline(cin, str);

    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());

    if (str == reversedStr) {
        cout << "\n\"" << str << "\" is a Palindrome.\n";
    } else {
        cout << "\n\"" << str << "\" is NOT a Palindrome.\n";
    }
}
void findSubstring() {
    string mainStr, subStr;
    cout << "Enter main string: ";
    getline(cin, mainStr);
    cout << "Enter substring to find: ";
    getline(cin, subStr);
    size_t foundPos = mainStr.find(subStr);

    if (foundPos != string::npos) {
        cout << "\nSuccess! Substring found starting at position/index: " << foundPos << "\n";
    } else {
        cout << "\nSubstring not found in the main string.\n";
    }
}
void changeCase() {
    string str;
    int option;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Convert to:\n1. UPPERCASE\n2. lowercase\nChoice: ";
    cin >> option;
    cin.ignore();

    if (option == 1) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        cout << "\nUppercase Result: " << str << "\n";
    } else if (option == 2) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        cout << "\nLowercase Result: " << str << "\n";
    } else {
        cout << "\nInvalid choice. Case conversion skipped.\n";
    }
}
