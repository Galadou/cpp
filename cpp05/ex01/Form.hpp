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
		
		Form(std::string name, int gradeToSign, int gradeToExec);
	
		std::string getName() const;
		bool		getSigned() const;
		int 		getGradeToSign() const;
		int			getGradeToExec() const;

		void	beSigned(Bureaucrat &src);

	private:
		struct GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade given is too low !");
			}
		};
		struct GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade given is too High !");
			}
		};
		struct AlreadySigned : public std::exception
		{
			const char* what() const throw()
			{
				return ("Form is already signed !");
			}
		};

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif