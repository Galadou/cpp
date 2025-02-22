#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

//cpy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &srcs)
{
	*this = srcs;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &srcs)
{ 
	if (this != &srcs)
		this->_grade = srcs._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException ();
	this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException ();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &src)
{
	try
	{
		src.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because " << e.what() << "." << std::endl;
		return;
	}
	std::cout << this->_name << " signed " << src.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}