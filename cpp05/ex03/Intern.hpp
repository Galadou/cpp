
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &srcs);
		Intern &operator=(Intern const &srcs);

	AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif