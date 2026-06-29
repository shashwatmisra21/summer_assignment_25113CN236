#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
void displayMenu();
void traverseArray(const int arr[], int size);
void insertElement(int arr[], int &size);
void deleteElement(int arr[], int &size);
int searchElement(const int arr[], int size, int key);

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverseArray(arr, size);
                break;
            case 2:
                insertElement(arr, size);
                break;
            case 3:
                deleteElement(arr, size);
                break;
            case 4: {
                if (size == 0) {
                    cout << "\nArray is empty! Nothing to search.\n";
                    break;
                }
                int key;
                cout << "Enter the element to search: ";
                cin >> key;
                int index = searchElement(arr, size, key);
                if (index != -1) {
                    cout << "\nElement found at index: " << index << "\n";
                } else {
                    cout << "\nElement not found in the array.\n";
                }
                break;
            }
            case 5:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\n====================================\n";
    cout << "   ARRAY OPERATIONS MENU SYSTEM     \n";
    cout << "====================================\n";
    cout << "1. Display (Traverse) Array\n";
    cout << "2. Insert Element\n";
    cout << "3. Delete Element\n";
    cout << "4. Search Element (Linear Search)\n";
    cout << "5. Exit\n";
    cout << "====================================\n";
}
void traverseArray(const int arr[], int size) {
    if (size == 0) {
        cout << "\nArray is empty!\n";
        return;
    }
    cout << "\nArray elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal elements: " << size << "\n";
}
void insertElement(int arr[], int &size) {
    if (size >= MAX_SIZE) {
        cout << "\nError: Array Overflow! Cannot insert more elements.\n";
        return;
    }

    int element, position;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter position (0 to " << size << "): ";
    cin >> position;
    if (position < 0 || position > size) {
        cout << "\nInvalid position! Position must be between 0 and " << size << ".\n";
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    cout << "\nElement inserted successfully!\n";
}
void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "\nError: Array Underflow! No elements to delete.\n";
        return;
    }

    int position;
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> position;
    if (position < 0 || position >= size) {
        cout << "\nInvalid position! Position must be between 0 and " << size - 1 << ".\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "\nElement deleted successfully!\n";
}
int searchElement(const int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}
