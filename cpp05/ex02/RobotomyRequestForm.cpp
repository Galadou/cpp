
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", false, 72, 45, target)
{

}

RobotomyRequestForm::~RobotomyRequestForm() {}

//cpy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &srcs) : AForm("Shruberry", false, 72, 45, "Roger")
{
	*this = srcs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &srcs)
{ 
	if (this != &srcs)
		this->AForm::operator=(srcs);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSigned();
	std::cout << "BRRRRRRRRRRRRR" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
		return;
	}
	std::cout << "Robotomy on " << this->getTarget() << " failed." << std::endl;
}