#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(std::string target);
		virtual ~AForm();
		AForm(AForm const &srcs);
		AForm &operator=(AForm const &srcs);

		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec, std::string target);
	
		std::string getName() const;
		bool		getSigned() const;
		int 		getGradeToSign() const;
		int			getGradeToExec() const;
		std::string	getTarget() const;

		void	beSigned(Bureaucrat &src);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:
		struct GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Grade is too low !");
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
		std::string			_target;

};

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif