#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string email;

public:
    // Konstruktor för att skapa en kontakt
    Contact(std::string name, std::string phoneNumber, std::string email);
    
    // Getter-metoder för att hämta kontaktinformation
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    
    // Metod för att visa kontaktinformation
    void displayContact() const;
};

#endif
