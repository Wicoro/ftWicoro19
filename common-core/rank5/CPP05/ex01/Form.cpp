#include "include/Form.hpp"

Form::Form(std::string name, int grade_s, int grade_e) : name(name), sign(false), grade_sign(grade_s), grade_exec(grade_e) {
	if (grade_s > 150 || grade_e > 150)
		throw GradeTooLowException("GradeTooLowException");
	if (grade_s < 1 || grade_e < 1)
		throw GradeTooHighException("GradeTooHighException");
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return *this;
}


Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::getSigned() const {
    return sign;
}

int Form::getGrade_sign() const {
    return grade_sign;
}

int Form::getGrade_exec() const {
    return grade_exec;
}
void Form::beSigned(const Bureaucrat& b) {
	if (sign)
		throw FormAlreadySigned("FormAlreadySigned");
	if (b.getGrade() > grade_sign)
		throw GradeTooLowException("GradeTooLowException");
	sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << " :\nGrade signing requirement : " << f.getGrade_sign() << "\nGrade exec requirement : " << f.getGrade_exec(); 
    return os;
}