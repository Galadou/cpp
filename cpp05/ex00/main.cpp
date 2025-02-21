
#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Bureaucrat bureaucrat("SALUT", 5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}