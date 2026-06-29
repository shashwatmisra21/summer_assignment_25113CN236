#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_ITEMS = 100; 
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};
void displayMenu();
void addItem(Item inventory[], int &itemCount);
void displayInventory(const Item inventory[], int itemCount);
void updateStock(Item inventory[], int itemCount);
void searchItem(const Item inventory[], int itemCount);

int main() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0; 
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addItem(inventory, itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                updateStock(inventory, itemCount);
                break;
            case 4:
                searchItem(inventory, itemCount);
                break;
            case 5:
                cout << "\nExiting Inventory Management System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid selection! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\n====================================\n";
    cout << "     INVENTORY MANAGEMENT SYSTEM    \n";
    cout << "====================================\n";
    cout << "1. Add New Item\n";
    cout << "2. View All Inventory Stock\n";
    cout << "3. Update Stock Quantity\n";
    cout << "4. Search Item by ID\n";
    cout << "5. Exit System\n";
    cout << "====================================\n";
}
void addItem(Item inventory[], int &itemCount) {
    if (itemCount >= MAX_ITEMS) {
        cout << "\nError: Warehouse inventory capacity is full!\n";
        return;
    }

    Item newItem;
    cout << "Enter Item ID (Integer): ";
    cin >> newItem.id;
    cin.ignore();
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            cout << "\nError: An item with ID " << newItem.id << " already exists!\n";
            return;
        }
    }

    cout << "Enter Item Name: ";
    getline(cin, newItem.name);

    cout << "Enter Initial Quantity: ";
    cin >> newItem.quantity;

    cout << "Enter Price Per Unit: ";
    cin >> newItem.price;

    inventory[itemCount] = newItem;
    itemCount++; 
    cout << "\nSuccess: Item added to stock catalog!\n";
}
void displayInventory(const Item inventory[], int itemCount) {
    if (itemCount == 0) {
        cout << "\nInventory catalog is currently empty!\n";
        return;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(10) << "ID" 
         << setw(25) << "Item Name" 
         << setw(12) << "Quantity" 
         << "Price ($)\n";
    cout << "-------------------------------------------------------------\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < itemCount; i++) {
        cout << left << setw(10) << inventory[i].id 
             << setw(25) << inventory[i].name 
             << setw(12) << inventory[i].quantity 
             << inventory[i].price << "\n";
    }
    cout << "-------------------------------------------------------------\n";
}
void updateStock(Item inventory[], int itemCount) {
    if (itemCount == 0) {
        cout << "\nInventory is empty. No stock values to modify.\n";
        return;
    }

    int searchId;
    cout << "Enter the Item ID to adjust stock level: ";
    cin >> searchId;

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            cout << "\nCurrent Details -> Name: " << inventory[i].name 
                 << " | Current Stock: " << inventory[i].quantity << "\n";
            
            cout << "Enter new quantity value: ";
            cin >> inventory[i].quantity;
            
            cout << "\nSuccess: Stock record rewritten correctly.\n";
            return;
        }
    }
    cout << "\nError: Item ID " << searchId << " not located in catalog records.\n";
}
void searchItem(const Item inventory[], int itemCount) {
    if (itemCount == 0) {
        cout << "\nInventory catalog is empty.\n";
        return;
    }

    int searchId;
    cout << "Enter Item ID to query: ";
    cin >> searchId;

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            cout << "\n--- Match Records Found ---\n";
            cout << "ID: " << inventory[i].id << "\n";
            cout << "Name: " << inventory[i].name << "\n";
            cout << "Quantity Instock: " << inventory[i].quantity << "\n";
            cout << fixed << setprecision(2) << "Unit Cost: $" << inventory[i].price << "\n";
            return;
        }
    }
    cout << "\nQuery Failed: No profile matches item reference ID " << searchId << ".\n";
}
