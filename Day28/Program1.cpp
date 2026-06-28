#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    bool isIssued;

public:
    Book(std::string bookId, std::string bookTitle, std::string bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(false) {}
    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }
    void displayBook() const {
        std::cout << std::left << std::setw(10) << id 
                  << std::setw(30) << title 
                  << std::setw(25) << author 
                  << (isIssued ? "Issued" : "Available") << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;
    auto findBookById(const std::string& id) {
        return std::find_if(books.begin(), books.end(), [&id](const Book& b) {
            return b.getId() == id;
        });
    }

public:
    void addBook() {
        std::string id, title, author;
        std::cout << "\nEnter Book ID: ";
        std::cin >> id;
        std::cin.ignore(); 

        if (findBookById(id) != books.end()) {
            std::cout << "Error: A book with this ID already exists!\n";
            return;
        }

        std::cout << "Enter Book Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author Name: ";
        std::getline(std::cin, author);

        books.emplace_back(id, title, author);
        std::cout << "Book added successfully!\n";
    }
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "\nThe library inventory is currently empty.\n";
            return;
        }

        std::cout << "\n---------------------------------------------------------------------------\n";
        std::cout << std::left << std::setw(10) << "ID" 
                  << std::setw(30) << "Title" 
                  << std::setw(25) << "Author" 
                  << "Status\n";
        std::cout << "---------------------------------------------------------------------------\n";
        for (const auto& book : books) {
            book.displayBook();
        }
        std::cout << "---------------------------------------------------------------------------\n";
    }
    void searchBook() {
        std::string id;
        std::cout << "\nEnter Book ID to search: ";
        std::cin >> id;

        auto it = findBookById(id);
        if (it != books.end()) {
            std::cout << "\nBook Found:\n";
            std::cout << "---------------------------------------------------------------------------\n";
            it->displayBook();
            std::cout << "---------------------------------------------------------------------------\n";
        } else {
            std::cout << "Book not found.\n";
        }
    }
    void issueBook() {
        std::string id;
        std::cout << "\nEnter Book ID to issue: ";
        std::cin >> id;

        auto it = findBookById(id);
        if (it == books.end()) {
            std::cout << "Book not found.\n";
        } else if (it->getIssuedStatus()) {
            std::cout << "Book is already issued to someone else.\n";
        } else {
            it->issueBook();
            std::cout << "Book successfully issued!\n";
        }
    }
    void returnBook() {
        std::string id;
        std::cout << "\nEnter Book ID to return: ";
        std::cin >> id;

        auto it = findBookById(id);
        if (it == books.end()) {
            std::cout << "Book not found.\n";
        } else if (!it->getIssuedStatus()) {
            std::cout << "This book was not issued. It is already in the library.\n";
        } else {
            it->returnBook();
            std::cout << "Book successfully returned to the inventory!\n";
        }
    }
};

int main() {
    Library myLibrary;
    int choice;

    do {
        std::cout << "\n===== Library Management System =====\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "=====================================\n";
        std::cout << "Enter your choice (1-6): ";
        
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 6: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        switch (choice) {
            case 1: myLibrary.addBook(); break;
            case 2: myLibrary.displayAllBooks(); break;
            case 3: myLibrary.searchBook(); break;
            case 4: myLibrary.issueBook(); break;
            case 5: myLibrary.returnBook(); break;
            case 6: std::cout << "\nExiting system. Goodbye!\n"; break;
            default: std::cout << "Invalid choice! Please select an option from 1 to 6.\n";
        }
    } while (choice != 6);
return 0;
}
