#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;
    std::string address;

public:
    Contact(std::string cName, std::string cPhone, std::string cEmail, std::string cAddress)
        : name(cName), phone(cPhone), email(cEmail), address(cAddress) {}

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    void setPhone(const std::string& newPhone) { phone = newPhone; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setAddress(const std::string& newAddress) { address = newAddress; }

    void displayContactRow() const {
        std::cout << std::left << std::setw(20) << name 
                  << std::setw(15) << phone 
                  << std::setw(25) << email 
                  << address << "\n";
    }
};

class AddressBook {
private:
    std::vector<Contact> contacts;
    auto findContactIterator(const std::string& searchName) {
        return std::find_if(contacts.begin(), contacts.end(), [&searchName](const Contact& c) {
            return c.getName() == searchName;
        });
    }

public:
    void addContact() {
        std::string name, phone, email, address;
        std::cout << "\nEnter Full Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        if (findContactIterator(name) != contacts.end()) {
            std::cout << "Error: A contact with this name already exists!\n";
            return;
        }

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Email Address: ";
        std::getline(std::cin, email);
        std::cout << "Enter Physical Address: ";
        std::getline(std::cin, address);

        contacts.emplace_back(name, phone, email, address);
        std::cout << "Contact saved successfully!\n";
    }
    void displayAllContacts() const {
        if (contacts.empty()) {
            std::cout << "\nYour address book is empty.\n";
            return;
        }

        std::cout << "\n---------------------------------------------------------------------------------------\n";
        std::cout << std::left << std::setw(20) << "Name" 
                  << std::setw(15) << "Phone" 
                  << std::setw(25) << "Email" 
                  << "Address\n";
        std::cout << "---------------------------------------------------------------------------------------\n";
        for (const auto& contact : contacts) {
            contact.displayContactRow();
        }
        std::cout << "---------------------------------------------------------------------------------------\n";
    }
    void searchContact() {
        std::string searchName;
        std::cout << "\nEnter Name to search: ";
        std::cin.ignore();
        std::getline(std::cin, searchName);

        auto it = findContactIterator(searchName);
        if (it != contacts.end()) {
            std::cout << "\nContact Found:\n";
            std::cout << "---------------------------------------------------------------------------------------\n";
            it->displayContactRow();
            std::cout << "---------------------------------------------------------------------------------------\n";
        } else {
            std::cout << "Contact not found.\n";
        }
    }
    void editContact() {
        std::string searchName;
        std::cout << "\nEnter Name of contact to edit: ";
        std::cin.ignore();
        std::getline(std::cin, searchName);

        auto it = findContactIterator(searchName);
        if (it == contacts.end()) {
            std::cout << "Contact not found.\n";
            return;
        }

        std::string buffer;
        std::cout << "Current Phone: " << it->getPhone() << " -> Enter new phone (or press Enter to skip): ";
        std::getline(std::cin, buffer);
        if (!buffer.empty()) it->setPhone(buffer);

        std::cout << "Current Email: " << it->getEmail() << " -> Enter new email (or press Enter to skip): ";
        std::getline(std::cin, buffer);
        if (!buffer.empty()) it->setEmail(buffer);

        std::cout << "Current Address: " << it->getAddress() << " -> Enter new address (or press Enter to skip): ";
        std::getline(std::cin, buffer);
        if (!buffer.empty()) it->setAddress(buffer);

        std::cout << "Contact updated successfully!\n";
    }
    void deleteContact() {
        std::string searchName;
        std::cout << "\nEnter Name of contact to delete: ";
        std::cin.ignore();
        std::getline(std::cin, searchName);

        auto it = findContactIterator(searchName);
        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully!\n";
        } else {
            std::cout << "Contact not found.\n";
        }
    }
};

int main() {
    AddressBook myAddressBook;
    int choice;

    do {
        std::cout << "\n===== Contact Management System =====\n";
        std::cout << "1. Add New Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Edit Contact\n";
        std::cout << "5. Delete Contact\n";
        std::cout << "6. Exit Application\n";
        std::cout << "=====================================\n";
        std::cout << "Enter choice (1-6): ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid entry. Enter a valid option from 1 to 6: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        switch (choice) {
            case 1: myAddressBook.addContact(); break;
            case 2: myAddressBook.displayAllContacts(); break;
            case 3: myAddressBook.searchContact(); break;
            case 4: myAddressBook.editContact(); break;
            case 5: myAddressBook.deleteContact(); break;
            case 6: std::cout << "\nExiting directory system. Goodbye!\n"; break;
            default: std::cout << "Selection out of bounds.\n";
        }
    } while (choice != 6);

    return 0;
}
