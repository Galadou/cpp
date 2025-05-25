#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	last_number = false;
	parsing(argc, argv, this->_deque_number);
	parsing(argc, argv, this->_vector_number);
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
		this->_vector_number = src._vector_number;
		this->_sorted_vector = src._sorted_vector;
		this->duration_vector = src.duration_vector;
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
		block *temp = new block;
		temp->value = nb;
		temp->pair = NULL;
		temp->my_place = -1;
		container.push_back(temp);
	}
}
void	PmergeMe::exec()
{
	//deque
	std::clock_t start_time = std::clock();
	fordJohnson(this->_deque_number, this->_sorted_deque);
	std::clock_t end_time = std::clock();
	this->duration_deque = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

	//vector
	start_time = std::clock();
	fordJohnson(this->_vector_number, this->_sorted_vector);
	end_time = std::clock();
	this->duration_vector = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;
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
		std::cout << " " << this->_sorted_deque.front()->value;
		delete this->_sorted_deque.front();
		this->_sorted_deque.pop_front();
	}
	std::cout << std::endl;
	std::cout << "After with vector:";
	while (this->_sorted_vector.size() > 0)
	{
		std::cout << " " << this->_sorted_vector.front()->value;
		delete this->_sorted_vector.front();
		this->_sorted_vector.erase(this->_sorted_vector.begin());
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << this->duration_deque << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << this->duration_vector << " us" << std::endl;
}

template <typename T>
static T find_pos(T start_it, T end_it, block *ptr)
{
	while (start_it != end_it)
	{
		T mid_it = start_it + (end_it - start_it) / 2;
		if ((*mid_it)->value < ptr->value)
			start_it = ++mid_it; // on avance de 1 car on veut l'element plus grand que mid_it
		else if ((*mid_it)->value > ptr->value)
			end_it = mid_it; // on recule jusqu'a mid_it
		else
			return (mid_it); // si on trouve, on retourne l'iterator
	}
	return (start_it);
}


//T<block *>
template <typename T>
void fordJohnson(T &stack, T &stack_final)
{
	typename T::iterator up_it;
	T	stack_smaller;
	T	stack_bigger;
	int	size = stack.size();

	if (size == 0)
		return;
	if (size == 1)
	{
		typename T::iterator inserted_it = stack_final.insert(stack_final.begin(), *stack.begin());
		size_t index = inserted_it - stack_final.begin(); //index = l'endroit trouver - le begin, donc ca donne l'index !
		(*stack_final.begin())->my_place = index;
		return;
	}

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
		if ((*it)->value < (*next)->value)
		{
			(*it)->pair = *next; //comme next est un iterator, *next = le pointeur de stock
			stack_smaller.push_back(*it);
			stack_bigger.push_back(*next);
		}
		else
		{
			(*next)->pair = *it;
			stack_smaller.push_back(*next);
			stack_bigger.push_back(*it);
		}
		it = ++next;
	}

	fordJohnson(stack_bigger, stack_final);

	for (typename T::iterator it = stack_smaller.begin(); it != stack_smaller.end(); ++it) // we insert all the smaller number with the binary sort.
	{
		if ((*it)->pair != NULL && (*it)->pair->my_place != (size_t)-1) //in case where it's NULL
			up_it = stack_final.begin() + (*it)->pair->my_place;
		else
			up_it = stack_final.end();
		typename T::iterator insert_pos = find_pos(stack_final.begin(), up_it, *it);
		typename T::iterator inserted_it = stack_final.insert(insert_pos, *it);

		(*it)->my_place = inserted_it - stack_final.begin();
		inserted_it++;
		while (inserted_it < stack_final.end())
		{
			(*inserted_it)->my_place += 1;
			inserted_it++;
		}
	}
}

