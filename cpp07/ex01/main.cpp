#include "iter.hpp"

void print(int nb)
{
	std::cout << nb << std::endl;
}

void print(std::string str)
{
	std::cout << str << std::endl;
}

int main( void )
{
	int tab[5] = {1, 2, 3, 4, 5};
	::iter(tab, 5, print);
	
	std::string array[2] = {"salut", "hey"};
	::iter(array, 2, print);
	return (0);
}