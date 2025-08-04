#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>

class PhoneBook {
private:
	Contact contacts[8];
	int		last_index;
public:
    PhoneBook() {}
    ~PhoneBook() {}

    void	addContact();
	void	searchContact();
	void	setLastIndex(int i);
	int		getLastIndex();
};

#endif // PHONEBOOK_HPP
