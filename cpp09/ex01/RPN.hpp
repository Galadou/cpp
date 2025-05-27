#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		void	parsing(char **argv);
		void	exec(char op);
		int getResult();

	private:
		std::stack<long int> _stack;
		int _result;
};

#endif