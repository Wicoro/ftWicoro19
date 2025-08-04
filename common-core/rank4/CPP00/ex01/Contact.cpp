/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:34 by norban            #+#    #+#             */
/*   Updated: 2025/08/04 14:55:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(const std::string &fname) {
	this->firstname = fname;
}

void	Contact::setLastName(const std::string &lname) {
	this->lastname = lname;
}

void	Contact::setNickname(const std::string &nname) {
	this->nickname = nname;
}

void	Contact::setPhoneNumber(const std::string &phone) {
	this->phone_nb = phone;
}

void	Contact::setSecret(const std::string &secret) {
	this->secret = secret;
}

std::string Contact::getFirstName() const {
	return this->firstname;
}

std::string Contact::getLastName() const {
	return this->lastname;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phone_nb;
}

std::string Contact::getSecret() const {
	return this->secret;
}