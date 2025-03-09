#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &srcs);
		Bureaucrat &operator=(Bureaucrat const &srcs);

		Bureaucrat(std::string const &name, int grade);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void	signForm(AForm &src);
		void	executeForm(AForm const & form);


	private:

		struct GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Error : Grade is too high !");
			}
		};
		struct GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Error : Grade is too low !");
			}
		};

		const std::string	_name;
		int					_grade;

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#include "AForm.hpp"

#endif