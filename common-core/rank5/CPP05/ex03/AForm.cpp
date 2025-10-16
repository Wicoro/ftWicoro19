#include "include/AForm.hpp"

AForm::AForm(std::string name, int grade_s, int grade_e) : name(name), sign(false), grade_sign(grade_s), grade_exec(grade_e)
{
	if (grade_s > 150 || grade_e > 150)
		throw GradeTooLowException("GradeTooLowException");
	if (grade_s < 1 || grade_e < 1)
		throw GradeTooHighException("GradeTooHighException");
}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return sign;
}

int AForm::getGrade_sign() const
{
	return grade_sign;
}

int AForm::getGrade_exec() const
{
	return grade_exec;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (sign)
		throw FormAlreadySigned("This form is already signed");
	if (b.getGrade() > grade_sign)
		throw GradeTooLowException("Bureaucrat's grade is too low to sign this form");
	sign = true;
}

void AForm::checkExec(const Bureaucrat& b) const {
	if (!sign)
		throw FormNotSigned("This form is not signed");
	if (b.getGrade() > grade_exec)
		throw GradeTooLowException("Bureaucrat's grade is too low to exec this form");
}

void AForm::execute(const Bureaucrat& b) const {
	checkExec(b);
	execImplement();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << " :\nGrade signing requirement : " << f.getGrade_sign() << "\nGrade exec requirement : " << f.getGrade_exec();
	return os;
}