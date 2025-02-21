
#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Form form;
		Bureaucrat bureaucrat("John", 6);
		//we look if John is well done.
		std::cout << bureaucrat << std::endl << std::endl;

		//bureaucrat try to sign, but he need to be lvl 5
		bureaucrat.signForm(form);
		std::cout << std::endl;

		//we look if form is signed, it shouldn't. We use the overload << like subject want.
		std::cout << form << std::endl << std::endl;
	
		//bureaucrat is now lvl 5.
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl << std::endl;
	
		//He retry to sign, should work.
		bureaucrat.signForm(form);
		std::cout << std::endl;

		//we look again if its signed now. It should be.
		std::cout << form << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}