
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	//?try to comment some block to check all test
	//try for president.
	try 
	{
		std::string name = "bob";
		PresidentialPardonForm President("John");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		//President.execute(bureaucrat);

		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(President);
		bureaucrat.signForm(President);
		President.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//test for Robotomy
	try 
	{
		std::string name = "bob";
		RobotomyRequestForm robot("John");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		robot.execute(bureaucrat);

		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(robot);
		robot.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//test for Robotomy
	try 
	{
		std::string name = "bob";
		RobotomyRequestForm robot("John");
		Bureaucrat bureaucrat(name, 6);

		//we try to execute without sign it and with a too low grade
		robot.execute(bureaucrat);

		//we increment it to has a good grade
		bureaucrat.incrementGrade();

		//now we sign vbefore, should work
		bureaucrat.signForm(robot);
		robot.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}