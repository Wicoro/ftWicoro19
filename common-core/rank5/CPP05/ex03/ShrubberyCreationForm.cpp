#include "include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execImplement() const {
	std::ofstream out((this->target + "_shrubbery").c_str());
	if (!out.is_open()) {
		std::cerr << "Error opening output file." << std::endl;
		return;
	}

	out <<
		"      /\\\n"
		"     /\\*\\\n"
		"    /\\O\\*\\\n"
		"   /*/\\/\\/\\\n"
		"  /\\O\\/\\*\\/\\\n"
		" /\\*\\/\\*\\/\\/\\\n"
		"/\\O\\/\\/*/\\/O/\\\n"
		"      ||\n"
		"      ||\n"
		"      ||\n";

	out.close();
	std::cout << "Shrubbery has been created in : " << target << "_shrubbery" << std::endl;
}
