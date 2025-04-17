
#ifndef MUTANTSTACKS_HPP
#define MUTANTSTACKS_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack(MutantStack const &src) {(void)src;};
		MutantStack& operator=(MutantStack const &src) {(void)src; return (*this);};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};



#endif