#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *addr, int len, void (*apply)(T))
{
	int i = 0;

	if (len <= 0)
	{
		std::cout << "Error, len isn't good." << std::endl;
		return;
	}
	if (addr == NULL)
	{
		std::cout << "Error, array = nullptr." << std::endl;
		return;
	}
	while (i < len)
	{
		apply(addr[i]);
		i++;
	}
}


#endif