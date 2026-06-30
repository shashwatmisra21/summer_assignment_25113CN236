#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_BOOKS = 100; 
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        isIssued = false;
    }
    void setData(int bId, string bTitle, string bAuthor) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        isIssued = false;
    }
    int getId() const { return id; }
    string getTitle() const { return title; }
    bool getIssueStatus() const { return isIssued; }
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }
    void displayRow() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << (isIssued ? "Issued" : "Available") << "\n";
    }
};
void displayMenu();
void addBook(Book library[], int &bookCount);
void viewBooks(const Book library[], int bookCount);
void searchBook(const Book library[], int bookCount);
void issueOrReturnBook(Book library[], int bookCount, bool processIssue);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addBook(library, bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueOrReturnBook(library, bookCount, true);  
                break;
            case 5:
                issueOrReturnBook(library, bookCount, false); 
                break;
            case 6:
                cout << "\nExiting Library System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option from 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\n====================================\n";
    cout << "        MINI LIBRARY SYSTEM         \n";
    cout << "====================================\n";
    cout << "1. Add New Book\n";
    cout << "2. View Cataloged Books\n";
    cout << "3. Search Book by Title\n";
    cout << "4. Issue / Check-out Book\n";
    cout << "5. Return Book to Shelf\n";
    cout << "6. Exit System\n";
    cout << "====================================\n";
}
void addBook(Book library[], int &bookCount) {
    if (bookCount >= MAX_BOOKS) {
        cout << "\nError: Library inventory tracks are full!\n";
        return;
    }

    int id;
    string title, author;

    cout << "Enter Book unique ID (Integer): ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getId() == id) {
            cout << "\nError: A book with Accession ID " << id << " already exists!\n";
            return;
        }
    }

    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);

    library[bookCount].setData(id, title, author);
    bookCount++;
    cout << "\nSuccess: Book recorded safely into systems ledger.\n";
}
void viewBooks(const Book library[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nNo records tracked yet inside inventory indexes.\n";
        return;
    }

    cout << "\n----------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ID" 
         << setw(30) << "Book Title" 
         << setw(25) << "Author" 
         << "Availability Status\n";
    cout << "----------------------------------------------------------------------------\n";

    for (int i = 0; i < bookCount; i++) {
        library[i].displayRow();
    }
    cout << "----------------------------------------------------------------------------\n";
}
void searchBook(const Book library[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nLibrary catalog database is empty.\n";
        return;
    }

    string query;
    cout << "Enter Book Title to search for: ";
    getline(cin, query);

    bool matchFound = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getTitle().find(query) != string::npos) {
            if (!matchFound) {
                cout << "\n--- Matching Log Items Identified ---\n";
                matchFound = true;
            }
            library[i].displayRow();
        }
    }

    if (!matchFound) {
        cout << "\nNo match entries discovered for target label \"" << query << "\".\n";
    }
}
void issueOrReturnBook(Book library[], int bookCount, bool processIssue) {
    if (bookCount == 0) {
        cout << "\nInventory records empty. Operations aborted.\n";
        return;
    }

    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (library[i].getId() == id) {
            if (processIssue) {
                if (library[i].getIssueStatus()) {
                    cout << "\nAlert: This book is already checked out to another member.\n";
                } else {
                    library[i].issueBook();
                    cout << "\nSuccess: Book \"" << library[i].getTitle() << "\" has been issued.\n";
                }
            } else {
                if (!library[i].getIssueStatus()) {
                    cout << "\nAlert: This item is already marked present on warehouse shelves.\n";
                } else {
                    library[i].returnBook();
                    cout << "\nSuccess: Book \"" << library[i].getTitle() << "\" returned safely.\n";
                }
            }
            return;
        }
    }
    cout << "\nError: Accession Reference ID " << id << " is not cataloged in systems database.\n";
}
