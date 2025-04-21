#include "RPN.hpp"

RPN::RPN()
{

}
RPN::~RPN()
{

}
RPN::RPN(const RPN &src)
{
	*this = src;
}
RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_result = src._result;
		this->_stack = src._stack;
	}
	return *this;
}

int RPN::getResult()
{
	if (this->_stack.size() != 1)
		throw std::invalid_argument("Error: bad input (too much number at the end of operation, should not happen).");
	this->_result = this->_stack.top();
	return (this->_result);
}

void	RPN::parsing(char **argv)
{
	int i = 1;
	long int nb;
	int count_sign = 0;
	int count_nb = 0;

	while (argv[i])
	{
		if (argv[i] == NULL || std::strlen(argv[i]) == 0) // check if argv[i] is null or empty
			throw std::invalid_argument("Error: empty or null argument.");
		if (isdigit(argv[i][0]) == false) // its not a number
		{
			if ((argv[i][0] != '+' && argv[i][0] != '-' && argv[i][0] != '*' && argv[i][0] != '/')|| std::strlen(argv[i]) > 1) // si pas un signe et + plus long que 1 de taille
				throw std::invalid_argument("Error: bad operator sign (+-*/).");
			//execute the operator
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Error: not enough number in stack.");
			exec(argv[i][0]);
			count_sign++;
			i++;
			continue;
		}

		nb = std::atol(argv[i]);
		if (nb < 0 || nb > 9)
			throw std::invalid_argument("Error: number out of range.");
		this->_stack.push((nb)); // push the number in the stack
		count_nb++;
		i++;
	}
	if (count_sign != count_nb - 1 || count_nb == 0 || count_sign == 0)
		throw std::invalid_argument("Error: bad input (need one less operator than number).");
}

void RPN::exec(char op)
{
	int number1;
	int number2;

	number2 = _stack.top(); // get the top element
	_stack.pop(); // remove the top element
	number1 = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(number1 + number2);
			break;
		case '-':
			_stack.push(number1 - number2);
			break;
		case '/':
			if (number2 == 0)
				throw std::invalid_argument("Error: division by zero.");
			_stack.push(number1 / number2);
			break;
		case '*':
			_stack.push(number1 * number2);
			break;
		default:
			break;
	}
}

