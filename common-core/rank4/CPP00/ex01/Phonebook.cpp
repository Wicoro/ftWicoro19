/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:34 by norban            #+#    #+#             */
/*   Updated: 2025/08/04 14:55:09 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact() {
    int i;
    std::string firstname, lastname, nickname, phone_nb, secret;

    if (getLastIndex() == 8)
		setLastIndex(0);
	i = getLastIndex();
		
    std::cout << "First name: ";
    if (!(std::cin >> firstname))
	{
		std::cout << "\nInvalid input : aborting ADD\n";
		std::cin.clear();
		return ;
	}
    std::cout << "Last name: ";
    if (!(std::cin >> lastname))
	{
		std::cout << "\nInvalid input : aborting ADD\n";
		std::cin.clear();
		return ;
	}
    std::cout << "Nickname: ";
    if (!(std::cin >> nickname))
	{
		std::cout << "\nInvalid input : aborting ADD\n";
		std::cin.clear();
		return ;
	}
	
    std::cout << "Phone number: ";
    if (!(std::cin >> phone_nb))
	{
		std::cout << "\nInvalid input : aborting ADD\n";
		std::cin.clear();
		return ;
	}
    std::cout << "Darkest secret: ";
    if (!(std::cin >> secret))
	{
		std::cout << "\nInvalid input : aborting ADD\n";
		std::cin.clear();
		return ;
	}
    this->contacts[i].setFirstName(firstname);
    this->contacts[i].setLastName(lastname);
    this->contacts[i].setNickname(nickname);
    this->contacts[i].setPhoneNumber(phone_nb);
    this->contacts[i].setSecret(secret);
	setLastIndex(getLastIndex() + 1);
	
    std::cout << "Contact added successfully!" << std::endl;
}


std::string formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    std::ostringstream out;
    out << std::setw(10) << field;
    return out.str();
}

void PhoneBook::searchContact() {
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (!contacts[i].getFirstName().empty()) {
			std::cout << std::setw(10) << i << "|"
						<< formatField(contacts[i].getFirstName()) << "|"
						<< formatField(contacts[i].getLastName()) << "|"
						<< formatField(contacts[i].getNickname()) << std::endl;
		}
	}
	
	int readindex;
	std::cout << "\nEnter contact ID: ";
	if (!(std::cin >> readindex)) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid ID\n";
			return ;
		}
		if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting\n";
		}
		return ;
	}
	if (readindex > 7 || readindex < 0 || contacts[readindex].getFirstName().empty())
		std::cout << "\nInvalid ID\n";
	else
		std::cout <<
					"FirstName : " << contacts[readindex].getFirstName() << std::endl <<
					"LastName : " << contacts[readindex].getLastName() << std::endl <<
					"Nickname : "	<< contacts[readindex].getNickname() << std::endl <<
					"Phone Number : " << contacts[readindex].getPhoneNumber() << std::endl;
}

void PhoneBook::setLastIndex(int i) {
	this->last_index = i;
}

int PhoneBook::getLastIndex() {
	return (this->last_index);
}
	
int main() {
    PhoneBook phonebook;
	std::string readline;

	phonebook.setLastIndex(0);
	while (true)
	{
		std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		if (!(std::cin >> readline)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting\n";
			}
			break;
		}
		if (readline == "ADD") {
			phonebook.addContact();
		}	
		else if (readline == "SEARCH") {
			phonebook.searchContact();
		}
		else if (readline == "EXIT")
			break ;
	}
    return 0;
}
