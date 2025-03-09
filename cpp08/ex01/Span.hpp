#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

//template <typename T>



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
		void	addManyNumbers(int nb);

	private:
		struct TooManyIntStored : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error: Too many int inside the array !");
			}
		};
		struct TooLittleIntStored : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error: Too little int inside the array !");
			}
		};
		Span();
		std::vector<int>	_array;
		unsigned int 		_max;
};

#endif