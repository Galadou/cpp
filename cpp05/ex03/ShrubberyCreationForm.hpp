#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
	

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &srcs);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &srcs);

		void	execute(Bureaucrat const & executor) const;

	private :
		struct GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade is too low to execute!");
			}
		};
		struct FormNotSigned : public std::exception
		{
			const char* what() const throw()
			{
				return ("Form is not signed !");
			}
		};
		struct ErrorOpening : public std::exception
		{
			const char* what() const throw()
			{
				return ("Error on open function !");
			}
		};
};

#endif