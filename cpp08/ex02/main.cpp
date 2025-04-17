#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; //function doesn't exist in std::list
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(42);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::iterator itf = std::find(mstack.begin(), mstack.end(), 42);
	if (itf != mstack.end())
		std::cout << "42 has been find in the container." << std::endl;
	else
		std::cout << "There is no 42 inside the container." << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

//TEST WITH REAL CONTAINER

// #include <list>

// int main()
// {
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	//std::cout << mstack.top() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(42);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	std::list<int>::iterator itf = std::find(mstack.begin(), mstack.end(), 42);
// 	if (itf != mstack.end())
// 		std::cout << "42 has been find in the container." << std::endl;
// 	else
// 		std::cout << "There is no 42 inside the container." << std::endl;
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	//std::stack<int> s(mstack);
// 	return (0);
// }