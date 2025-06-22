#include <iostream>
#include <vector>
#include "Contact.h"

class ContactBook {
private:
    std::vector<Contact> contacts;

public:
    // Lägg till en ny kontakt
    void addContact(std::string name, std::string phoneNumber, std::string email) {
        contacts.push_back(Contact(name, phoneNumber, email));
        std::cout << "Contact added successfully.\n";
    }

    // Ta bort en kontakt baserat på namn
    void removeContact(std::string name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getName() == name) {
                contacts.erase(it);
                std::cout << "Contact removed successfully.\n";
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }

    // Visa alla kontakter
    void showAllContacts() const {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }
        for (const auto& contact : contacts) {
            contact.displayContact();
            std::cout << "------------------\n";
        }
    }

    // Sök efter en kontakt baserat på namn
    void searchContact(std::string name) const {
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                contact.displayContact();
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }
};

int main() {
    ContactBook myContacts;  // Skapa en kontaktbok
    int choice;
    std::string name, phoneNumber, email;

    do {
        std::cout << "\nContact Book Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Remove Contact\n";
        std::cout << "3. Show All Contacts\n";
        std::cout << "4. Search Contact\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin.ignore();  // Ignorerar newline från föregående input
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                myContacts.addContact(name, phoneNumber, email);
                break;

            case 2:
                std::cout << "Enter name of contact to remove: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                myContacts.removeContact(name);
                break;

            case 3:
                myContacts.showAllContacts();
                break;

            case 4:
                std::cout << "Enter name to search: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                myContacts.searchContact(name);
                break;

            case 5:
                std::cout << "Exiting the program.\n";
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
