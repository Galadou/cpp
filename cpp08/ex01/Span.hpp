#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	public:
		Span(unsigned int max);
		~Span();
		Span(Span const &src);
		Span& operator=(Span const &src);

		void	addNumber(int nb);
		int	shortestSpan();
		int	longestSpan();
		void	addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		struct TooManyIntStored : public std::exception
		{
			const char *what() const throw();
		};
		struct TooLittleIntStored : public std::exception
		{
			const char *what() const throw();
		};
		Span();
		std::vector<int>	_array;
		unsigned int 		_max;
};

#endif