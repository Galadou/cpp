#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Bob") {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &srcs)
{
	*this = srcs;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &srcs)
{ 
	if (this != &srcs)
	{
		this->_grade = srcs._grade;
	}
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
	this->_grade = grade;
}

std::string	Bureaucrat::getName()
{
	return (this->_name);
}
int			Bureaucrat::getGrade()
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade()
{

}

void		Bureaucrat::decrementGrade()
{

}