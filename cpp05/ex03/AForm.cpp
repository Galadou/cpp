
#include "AForm.hpp"

AForm::AForm(std::string target) : _name("Bob"), _signed(false), _gradeToSign(5), _gradeToExec(1), _target(target) {}

AForm::~AForm() {}

//cpy constructor
AForm::AForm(AForm const &srcs) : _name("Bob"), _signed(false), _gradeToSign(5), _gradeToExec(1), _target("Roger")
{
	*this = srcs;
}

AForm &AForm::operator=(AForm const &srcs)
{ 
	if (this != &srcs)
	{
		this->_signed = srcs._signed;
		this->_target = srcs._target;
	}

	return (*this);
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec, std::string target) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooLowException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooHighException();
	this->_signed = isSigned;
	this->_target = target;
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

std::string	AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_signed)
		throw AlreadySigned();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &src)
{
	out << src.getName() << " need grade " << src.getGradeToSign() \
	<< " to be signed and grade " << src.getGradeToExec() << " to be executed. Is signed: " << src.getSigned();
	return (out);
}