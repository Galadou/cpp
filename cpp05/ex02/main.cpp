
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try 
	{
		std::string name = "bob";
		PresidentialPardonForm President;
		Bureaucrat Bureaucrat(name, 5);

		Bureaucrat.signForm(President);
		//FAIRE OPLUS DE TEST
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}