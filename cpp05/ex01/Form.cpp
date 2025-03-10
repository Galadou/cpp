
#include "Form.hpp"

Form::Form() : _name("Bob"), _signed(false), _gradeToSign(5), _gradeToExec(1) {}

Form::~Form() {}

//cpy constructor
Form::Form(Form const &srcs) : _name("Bob"), _signed(false), _gradeToSign(5), _gradeToExec(1)
{
	*this = srcs;
}

Form &Form::operator=(Form const &srcs)
{ 
	if (this != &srcs)
		this->_signed = srcs._signed;
	return (*this);
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_signed)
		throw AlreadySigned();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &src)
{
	out << src.getName() << " need grade " << src.getGradeToSign() \
	<< " to be signed and grade " << src.getGradeToExec() << " to be executed. Is signed: " << src.getSigned();
	return (out);
}