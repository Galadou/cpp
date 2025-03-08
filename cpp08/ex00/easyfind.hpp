#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void easyfind(T &param, int nb)
{
	typename T::iterator pos;

	pos = std::find(param.begin(), param.end(), nb);
	if (pos == param.end())
		throw std::invalid_argument("The number isn't in this container.");
}

#endif