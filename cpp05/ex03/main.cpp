
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
		Bureaucrat bureaucrat(name, 151);
		Intern coffeMaker;

		form = coffeMaker.makeForm("Robotomy request", "José");
		std::cout << "Form is " << form->getName() << std::endl;
		std::cout << "And is target is " << form->getTarget() << std::endl;
		
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;
}