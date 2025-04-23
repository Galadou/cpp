#include "Span.hpp"

int main()
{
	try
	{
		Span span1 = Span(5);

		span1.addNumber(6);
		span1.addNumber(3);
		span1.addNumber(17);
		span1.addNumber(9);
		span1.addNumber(11);
		std::cout << span1.shortestSpan() << std::endl;
		std::cout << span1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Span span2(15000);

		//test exeption
		try
		{
			std::cout << span2.shortestSpan() << std::endl;
			std::cout << span2.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		//test with addManyNumber
		std::vector<int> numbers;
		for (int i = 0; i < 15000; i++)
			numbers.push_back(i);

		span2.addManyNumbers(numbers.begin(), numbers.end());
		std::cout << span2.shortestSpan() << std::endl;
		std::cout << span2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}