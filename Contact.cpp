#include "Contact.h"
#include <iostream>

Contact::Contact(std::string name, std::string phoneNumber, std::string email) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getEmail() const {
    return email;
}

void Contact::displayContact() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "Email: " << email << "\n";
}
