#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &srcs);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &srcs);

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
};

#endif