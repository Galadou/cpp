
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	//?try to comment some block to check all test
	//test for president.
	try 
	{
		std::string name = "bob";
		PresidentialPardonForm President("John");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		bureaucrat.executeForm(President);


		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(President);
		bureaucrat.signForm(President);
		bureaucrat.executeForm(President);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	//test for Robotomy
	try 
	{
		std::string name = "bob";
		RobotomyRequestForm robot("Tommy");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		bureaucrat.executeForm(robot);

		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(robot);
		bureaucrat.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	//test for Shruberry
	try 
	{
		std::string name = "bob";
		ShrubberyCreationForm Shrub("Patrik");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		bureaucrat.executeForm(Shrub);

		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(Shrub);
		bureaucrat.executeForm(Shrub);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}