
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		std::string name = "bob";
		Bureaucrat bureaucrat(name, 6);
		Intern coffeMaker;
		AForm *form;

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
	
}