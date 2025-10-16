#include "include/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {
    return target;
}

void PresidentialPardonForm::execImplement() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
