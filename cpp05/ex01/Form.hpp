#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		~Form();
		Form(Form const &srcs);
		Form &operator=(Form const &srcs);
	
		std::string getName() const;
		bool		getSigned() const;
		int 		getGradeToSign() const;
		int			getGradeToExec() const;

		void	beSigned(Bureaucrat &src);

	private:
		struct GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade is too high !");
			}
		};
		struct GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade is too low !");
			}
		};

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif