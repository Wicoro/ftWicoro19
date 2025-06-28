#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    Contact contacts[8];

    PhoneBook() {}
    ~PhoneBook() {}

    void addContact();
	void searchContact();
};

#endif // PHONEBOOK_HPP
