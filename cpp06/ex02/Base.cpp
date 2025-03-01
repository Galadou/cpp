#include "Base.hpp"

Base::~Base()
{
	
}

Base	* generate(void)
{
	int nb;
	std::srand(time(NULL));
	nb = std::rand() % 3;
	switch (nb)
	{
		case 0:
		{
			std::cout << "One A* class has been generated." << std::endl;
			return (new A());
		}
		case 1:
		{
			std::cout << "One B* class has been generated." << std::endl;
			return (new B());
		}
		case 2:
		{
			std::cout << "One C* class has been generated." << std::endl;
			return (new C());
		}
		default:
			return (NULL);
	}
}

void	identify(Base * p)
{
	if (!p)
		std::cout << "Error: pointer p is not set !" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "The type of Base *p is : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type of Base *p is : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type of Base *p is : C" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The type of Base &p is : A" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "The type of Base &p is : B" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "The type of Base &p is : C" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
	
}