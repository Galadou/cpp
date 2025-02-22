#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &srcs);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &srcs);

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