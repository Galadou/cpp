#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &srcs);
		Bureaucrat &operator=(Bureaucrat const &srcs);

		Bureaucrat(std::string const &name, int grade);

		std::string	getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();

	private:

		struct GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Error : Grade is too hight !");
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

#endif