
#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern()
{

}
Intern::Intern(Intern const &srcs)
{
	*this = srcs;
}

Intern &Intern::operator=(Intern const &srcs)
{
	(void)srcs;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	int i;
	AForm *result;
	std::string FormArray[3] = {"President request", "Robotomy request", "Shruberry"};

	for (i = 0; i < 3; i++) {
		if (FormArray[i] == formName) {
			break;
		}
	}

	switch (i)
	{
		case 0:
			result = new PresidentialPardonForm(formTarget);
			break;
		case 1:
			result = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			result = new ShrubberyCreationForm(formTarget);
			break;
		default:
			throw std::invalid_argument("Form name given isn't valid.");
	}
	std::cout << "Intern creates " << result->getName() << std::endl;
	return (result);
}