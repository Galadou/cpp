#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	last_number = false;
	parsing(argc, argv, this->_deque_number);
	parsing(argc, argv, this->_list_number);
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_deque_number = src._deque_number;
		this->_sorted_deque = src._sorted_deque;
		this->duration_deque = src.duration_deque;
		this->last_number = src.last_number;
		this->_list_number = src._list_number;
		this->_sorted_list = src._sorted_list;
		this->duration_list = src.duration_list;
	}
	return (*this);
}

template <typename T>
void PmergeMe::parsing(int argc, char **argv, T &container)
{
	if (argc < 2)
		throw std::invalid_argument("Error: Not enought param.");
	if (argc > 50000)
		throw std::invalid_argument("Error: too much param.");
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == NULL || strlen(argv[i]) == 0)
			throw std::invalid_argument("Error: empty or null argument.");
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (isdigit(argv[i][j]) == false)
				throw std::invalid_argument("Error: only positive numbers are allowed.");
		}
		long int nb = std::atol(argv[i]);
		if (nb < 1 || nb > 2147483647)
			throw std::invalid_argument("Error: number out of range.");
		container.push_back(nb);
	}
}
void	PmergeMe::exec()
{
	//deque
	std::clock_t start_time = std::clock();
	this->_sorted_deque = fordJohnson(this->_deque_number);
	std::clock_t end_time = std::clock();
	this->duration_deque = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

	//list
	start_time = std::clock();
	this->_sorted_list = fordJohnson(this->_list_number);
	end_time = std::clock();
	this->duration_list = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

}

void	PmergeMe::print_value(int argc, char **argv)
{
	int i = 1;

	std::cout << "Before:";
	while (argv[i] != NULL)
	{
		std::cout << " " << argv[i];
		i++;
	}
	std::cout << std::endl << "After with deque:";
	while (this->_sorted_deque.size() > 0)
	{
		std::cout << " " << this->_sorted_deque.front();
		this->_sorted_deque.pop_front();
	}
	std::cout << std::endl;

	std::cout << "After with list:";
	while (this->_sorted_list.size() > 0)
	{
		std::cout << " " << this->_sorted_list.front();
		this->_sorted_list.pop_front();
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << this->duration_deque << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << this->duration_list << " us" << std::endl;
}

template <typename T>
static T find_pos(T start_it, T end_it, int nb)
{
	while (start_it != end_it)
	{
		typename std::iterator_traits<T>::difference_type dist = std::distance(start_it, end_it); //find the type of iterator and calculate the range between start_it and end_it
		T mid = start_it;
		std::advance(mid, dist / 2); // move mid to dist/n pos
		if (nb <= *mid)
			end_it = mid;
		else
		{
			start_it = mid;
			++start_it;
		}
	}
	return (start_it);
}

template <typename T>
T fordJohnson(T &stack)
{
	T	stack_smaller;
	T	stack_bigger;
	T	stack_final;
	int	size = stack.size();

	if (size == 0)
		return (T());
	if (size == 1)
		return (stack);

	typename T::iterator it = stack.begin();
	while (it != stack.end())
	{
		typename T::iterator next = it;
		++next;
		if (next == stack.end()) // in case where it's not pair, there is a number alone
		{
			stack_bigger.push_back(*it);
			break;
		}
		if (*it < *next)
		{
			stack_smaller.push_back(*it);
			stack_bigger.push_back(*next);
		}
		else
		{
			stack_smaller.push_back(*next);
			stack_bigger.push_back(*it);
		}
		it = ++next;
	}

	stack_final = fordJohnson(stack_bigger); //recursive

	for (typename T::iterator it = stack_smaller.begin(); it != stack_smaller.end(); ++it) // we insert all the smaller number with the binary sort.
	{
		typename T::iterator insert_pos = find_pos(stack_final.begin(), stack_final.end(), *it);
		stack_final.insert(insert_pos, *it);
	}

	return (stack_final);
}

