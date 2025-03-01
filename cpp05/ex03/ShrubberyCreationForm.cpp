
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry", false, 145, 137, target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

//cpy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &srcs) : AForm("Shruberry", false, 145, 137, "Roger")
{
	*this = srcs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &srcs)
{ 
	if (this != &srcs)
		this->AForm::operator=(srcs);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		outfileName;
	std::ofstream	outfile;

	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSigned();
	outfileName = this->getTarget() + "_shrubbery";
	outfile.open(outfileName.c_str(), std::ofstream::out);
	if (!outfile.is_open())
		throw ErrorOpening();

	outfile << "              /\\              /\\            " << std::endl;
	outfile << "             /  \\            /  \\           " << std::endl;
	outfile << "            /    \\          /    \\          " << std::endl;
	outfile << "            /    \\          /    \\          " << std::endl;
	outfile << "           /      \\        /      \\         " << std::endl;
	outfile << "          /        \\      /        \\        " << std::endl;
	outfile << "          /        \\      /        \\        " << std::endl;
	outfile << "         /          \\    /          \\       " << std::endl;
	outfile << "         ------------     ------------        " << std::endl;
	outfile << "              ||               ||             " << std::endl;

	outfile.close();
}