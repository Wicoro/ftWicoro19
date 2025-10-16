#include <iostream>
#include "include/Brain.hpp"

Brain::Brain() : last_idea(0) {
	std::cout << "Default constructor called, brain was created!" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; ++i)
		idea[i] = other.idea[i];
	last_idea = other.last_idea;
	std::cout << "Copy constructor called for brain" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			idea[i] = other.idea[i];
		last_idea = other.last_idea;
		std::cout << "Copy assignment operator called for brain" << std::endl;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Destructor called : brain was destroyed!" << std::endl;
}



int Brain::addIdea(std::string str) {
	if (last_idea >= 100)
		last_idea = 0;
	idea[last_idea++] = str;
	return last_idea - 1;
}

void Brain::forgetIdea(int i) {
	if (i >= 0 && i < last_idea)
		idea[i] = "";
}

std::string Brain::getIdea(int i) const {
	if (i >= 0 && i < 100)
		return idea[i];
	return "";
}
