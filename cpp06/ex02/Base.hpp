#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib> //for rand
#include <ctime>

class Base
{
	public:
	virtual ~Base();
};

Base	* generate(void);
void	identify(Base * p);
void	identify(Base & p);

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#endif