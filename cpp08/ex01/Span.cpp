#include "Span.hpp"

Span::Span(unsigned int max)
{
	if (max > 50000 || max < 1)
		throw std::invalid_argument("Error: Cannot create Span with this param (too big or too small).");
	this->_max = max;
	std::srand(time(NULL));
}

Span::Span() {}

Span::~Span() {}

Span::Span(Span const &src)
{
	*this = src;
}

Span& Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_array = src._array;
		this->_max = src._max;
	}
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (this->_array.size() == this->_max)
		throw TooManyIntStored();
	this->_array.push_back(nb);
}

int	Span::shortestSpan()
{
	std::vector<int> buf(this->_array); //constructor by copy of vector
	int nb;

	if (this->_array.size() < 2)
		throw TooLittleIntStored();
	std::sort(buf.begin(), buf.end());
	nb = buf[1] - buf[0];
	for (size_t i = 1; i < buf.size(); i++)
	{
		if (buf[i] - buf[i - 1] < nb)
			nb = buf[i] - buf[i - 1];
	}
	return (nb);
}

int	Span::longestSpan()
{
	std::vector<int> buf(this->_array);

	if (this->_array.size() < 2)
		throw TooLittleIntStored();
	std::sort(buf.begin(), buf.end());
	return (buf[buf.size() - 1] - buf[0]);
}

void	Span::addManyNumbers(int nb)
{
	int number;

	try
	{
		for (int i = 0; i < nb; i++)
		{
			number = std::rand();
			this->addNumber(number);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}