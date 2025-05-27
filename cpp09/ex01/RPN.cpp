#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

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
	return (*this);
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
	std::string argument = argv[1];
	std::istringstream iss(argument);
	
	while (iss >> argument)
	{
		if (argument.size() != 1)
			throw std::invalid_argument("Error: empty, null or wrong argument.");
		if (isdigit(argument[0]) == false)
		{
			if ((argument[0] != '+' && argument[0] != '-' && argument[0] != '*' && argument[0] != '/'))
				throw std::invalid_argument("Error: bad operator sign (+-*/).");
			//execute the operator
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Error: not enough number in stack.");
			exec(argument[0]);
			count_sign++;
			i++;
			continue;
		}
		nb = std::atol(argument.c_str());
		if (nb < 0 || nb > 9)
			throw std::invalid_argument("Error: number out of range.");
		this->_stack.push((nb));
		count_nb++;
	}
	if (count_sign != count_nb - 1 || count_nb == 0 || count_sign == 0)
		throw std::invalid_argument("Error: bad input (need one less operator than number).");
}

void RPN::exec(char op)
{
	long int number1;
	long int number2;
	long int result;

	number2 = _stack.top(); // get the top element
	_stack.pop(); // remove the top element
	number1 = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			result = number1 + number2;
			break;
		case '-':
			result = number1 - number2;
			break;
		case '/':
			if (number2 == 0)
				throw std::invalid_argument("Error: division by zero.");
			result = number1 / number2;
			break;
		case '*':
			result = number1 * number2;
			break;
		default:
			result = -2147483649;
	}
	if (result < -2147483648 || result > 2147483647)
		throw std::invalid_argument("One result is out of bounds.");
	_stack.push(result);
}

