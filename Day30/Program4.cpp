#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_ITEMS = 50;  
const int CART_SIZE = 20; 
int itemIds[MAX_ITEMS] = {101, 102, 103, 104, 105};
string itemNames[MAX_ITEMS] = {"Organic Milk 1L", "Whole Wheat Bread", "Farm Fresh Eggs 12pk", "Dark Roast Coffee", "Potato Chips XL"};
double itemPrices[MAX_ITEMS] = {3.49, 2.29, 4.19, 8.99, 3.99};
int itemStocks[MAX_ITEMS] = {25, 15, 30, 10, 40};
int totalProducts = 5;
void displayMainMenu();
void viewStoreInventory();
void addNewProduct();
void processCustomerBill();
int findProductIndexById(int id);

int main() {
    int choice;

    do {
        displayMainMenu();
        cout << "Select a module choice (1-4): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                viewStoreInventory();
                break;
            case 2:
                addNewProduct();
                break;
            case 3:
                processCustomerBill();
                break;
            case 4:
                cout << "\nShutting down POS terminal software core. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid input flag selected! Re-try options 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}
void displayMainMenu() {
    cout << "\n=========================================\n";
    cout << "     SUPERMARKET POINT-OF-SALE SYSTEM    \n";
    cout << "=========================================\n";
    cout << "1. View Catalog & Stock Status\n";
    cout << "2. Add New Product to Catalog\n";
    cout << "3. Create New Customer Order / Bill\n";
    cout << "4. Exit Terminal\n";
    cout << "=========================================\n";
}
void viewStoreInventory() {
    cout << "\n------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ITEM ID" 
         << setw(28) << "PRODUCT DESCRIPTION" 
         << setw(15) << "UNIT PRICE" 
         << "STOCK LEVEL\n";
    cout << "------------------------------------------------------------------------\n";
    
    cout << fixed << setprecision(2);
    for (int i = 0; i < totalProducts; i++) {
        cout << left << setw(10) << itemIds[i] 
             << setw(28) << itemNames[i] 
             << "$" << setw(14) << itemPrices[i] 
             << itemStocks[i] << " units\n";
    }
    cout << "------------------------------------------------------------------------\n";
}
void addNewProduct() {
    if (totalProducts >= MAX_ITEMS) {
        cout << "\nInventory registry database error: Allocation ceiling overflow!\n";
        return;
    }

    int tempId;
    cout << "Enter new unique product serial ID code: ";
    cin >> tempId;
    cin.ignore();
    if (findProductIndexById(tempId) != -1) {
        cout << "\nAborted: Product Code " << tempId << " is already bound to another item.\n";
        return;
    }

    itemIds[totalProducts] = tempId;

    cout << "Enter short product descriptive label name: ";
    getline(cin, itemNames[totalProducts]);

    cout << "Enter item market sales value retail price ($): ";
    cin >> itemPrices[totalProducts];

    cout << "Enter current starting structural inventory count: ";
    cin >> itemStocks[totalProducts];

    totalProducts++;
    cout << "\nProduct catalog matrix updated successfully!\n";
}
void processCustomerBill() {
    if (totalProducts == 0) {
        cout << "\nOperation failure: Can't parse transactions across empty databases.\n";
        return;
    }
    int cartIds[CART_SIZE];
    int cartQuantities[CART_SIZE];
    int cartItemCount = 0;

    char addMore = 'y';
    cout << "\n--- Initializing New Customer Cart Session ---\n";

    while (addMore == 'y' || addMore == 'Y') {
        if (cartItemCount >= CART_SIZE) {
            cout << "\nNotice: Individual customer basket limit thresholds reached.\n";
            break;
        }

        int inputId, quantity;
        cout << "Scan / Enter product identification serial lookup tag: ";
        cin >> inputId;

        int productIdx = findProductIndexById(inputId);

        if (productIdx == -1) {
            cout << "Barcode scanning fault: Item reference ID code not found in directory.\n";
        } else {
            cout << "Product Identified: " << itemNames[productIdx] << " ($" << itemPrices[productIdx] << ")\n";
            cout << "Enter purchase quantity: ";
            cin >> quantity;

            if (quantity <= 0) {
                cout << "Invalid quantity assignment entry aborted.\n";
            } else if (quantity > itemStocks[productIdx]) {
                cout << "Inventory Stock Shortage! Only " << itemStocks[productIdx] << " units available.\n";
            } else {
                cartIds[cartItemCount] = productIdx; 
                cartQuantities[cartItemCount] = quantity;
                cartItemCount++;

                itemStocks[productIdx] -= quantity;
                cout << "Item mapped into customer basket slot correctly.\n";
            }
        }

        cout << "Add another product item loop tag down? (y/n): ";
        cin >> addMore;
    }
    if (cartItemCount > 0) {
        double subtotal = 0;
        cout << "\n======================================================\n";
        cout << "                  OFFICIAL TAX INVOICE                 \n";
        cout << "======================================================\n";
        cout << left << setw(25) << "ITEM DESCRIPTION" 
             << setw(10) << "QTY" 
             << setw(12) << "UNIT PRICE" 
             << "TOTAL ($)\n";
        cout << "------------------------------------------------------\n";
        
        cout << fixed << setprecision(2);
        for (int i = 0; i < cartItemCount; i++) {
            int dbIndex = cartIds[i];
            int qtyBought = cartQuantities[i];
            double costCalculated = itemPrices[dbIndex] * qtyBought;
            subtotal += costCalculated;

            cout << left << setw(25) << itemNames[dbIndex] 
                 << setw(10) << qtyBought 
                 << "$" << setw(11) << itemPrices[dbIndex] 
                 << costCalculated << "\n";
        }

        double retailSalesTax = subtotal * 0.08; 
        double finalGrandPayable = subtotal + retailSalesTax;

        cout << "------------------------------------------------------\n";
        cout << right << setw(40) << "Order Net Subtotal: $" << subtotal << "\n";
        cout << right << setw(40) << "Sales Tax Surcharge (8%): $" << retailSalesTax << "\n";
        cout << right << setw(40) << "Total Balanced Due Amount: $" << finalGrandPayable << "\n";
        cout << "======================================================\n";
        cout << "          Thank you for shopping with us!             \n";
        cout << "======================================================\n";
    } else {
        cout << "\nCheckout execution sequence abandoned. Customer basket registered empty.\n";
    }
}
int findProductIndexById(int id) {
    for (int i = 0; i < totalProducts; i++) {
        if (itemIds[i] == id) {
            return i; 
        }
    }
    return -1; 
}
