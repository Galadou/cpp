
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("President request", false, 25, 5, target)
{

}

PresidentialPardonForm::~PresidentialPardonForm() {}

//cpy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &srcs) : AForm("President request", false, 25, 5, "Roger")
{
	*this = srcs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &srcs)
{ 
	if (this != &srcs)
		this->AForm::operator=(srcs);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSigned();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}