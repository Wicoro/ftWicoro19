#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {}

Bureaucrat::Bureaucrat(int g) : name("John Doe"), grade(g) {
	if (grade <= 0)
		throw GradeTooHighException("GradeTooHighException");
	if (grade > 150)
		throw GradeTooLowException("GradeTooLowException");
}

Bureaucrat::Bureaucrat(std::string name, int g) : name(name), grade(g) {
	if (grade <= 0)
		throw GradeTooHighException("GradeTooHighException");
	if (grade > 150)
		throw GradeTooLowException("GradeTooLowException");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade == 1)
		throw GradeTooHighException("GradeTooHighException");
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == 150)
		throw GradeTooLowException("GradeTooLowException");
	grade++;
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << f.getName()
		          << " because : " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm & f) const {
	try {
		f.execute(*this);
	} catch (std::exception& e) {
		std::cout << name << "couldn't execute " << f.getName()
				  << " because : " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
