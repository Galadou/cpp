
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	AForm *form = NULL;
	try
	{
		std::string name = "bob";
		Bureaucrat bureaucrat(name, 6);
		Intern coffeMaker;

		form = coffeMaker.makeForm("Robotomy request", "José");
		std::cout << "Form is " << form->getName() << std::endl;
		std::cout << "And it's target is " << form->getTarget() << std::endl;

		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;
}