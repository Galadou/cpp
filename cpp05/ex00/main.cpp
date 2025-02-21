
#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Bureaucrat bureaucrat("John", 3);

		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat bureaucrat("Johnny", 148);

		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}