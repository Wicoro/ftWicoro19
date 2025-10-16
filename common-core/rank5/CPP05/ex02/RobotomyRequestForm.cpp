#include "include/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
    return target;
}
void RobotomyRequestForm::execImplement() const {
	std::cout << "* drilling noises * VRRRRRRRRRRR... " << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}
