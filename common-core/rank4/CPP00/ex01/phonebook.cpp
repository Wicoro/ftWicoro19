/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:34 by norban            #+#    #+#             */
/*   Updated: 2025/05/19 11:57:36 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

void PhoneBook::addContact() {
    int i;
    std::string firstname, lastname, nickname, phone_nb, secret;

    for (i = 0; i < 8; i++) {
        if (this->contacts[i].firstname.empty()) {
            break;
        }
    }
    if (i == 8) {
        std::cout << "Phone Book is full!" << std::endl;
        return;
    }

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
    this->contacts[i].firstname = firstname;
    this->contacts[i].lastname = lastname;
    this->contacts[i].nickname = nickname;
    this->contacts[i].phone_nb = phone_nb;
    this->contacts[i].secret = secret;

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
				<< std::setw(10) << "Darkest secret" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (!contacts[i].firstname.empty()) {
			std::cout << std::setw(10) << i << "|"
						<< formatField(contacts[i].firstname) << "|"
						<< formatField(contacts[i].lastname) << "|"
						<< formatField(contacts[i].nickname) << std::endl;
		}
	}
}

int main() {
    PhoneBook phonebook;
	std::string readline;

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
