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
		block *temp = new block;
		temp->value = nb;
		temp->pair = NULL;
		temp->my_place = NULL;
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

	std::cout << std::endl << " NEXT" << std::endl << std::endl;

	//list
	start_time = std::clock();
	fordJohnson(this->_list_number, this->_sorted_list);
	end_time = std::clock();
	this->duration_list = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

	std::cout << std::endl << " NEXT" << std::endl << std::endl;


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
		if (this->_sorted_deque.front()->my_place)
			delete static_cast<std::deque<block *>::iterator*>(this->_sorted_deque.front()->my_place);
		delete this->_sorted_deque.front();
		this->_sorted_deque.pop_front();
	}
	std::cout << std::endl;

	std::cout << "After with list:";
	while (this->_sorted_list.size() > 0)
	{
		std::cout << " " << this->_sorted_list.front()->value;
		if (this->_sorted_list.front()->my_place)
			delete static_cast<std::deque<block *>::iterator*>(this->_sorted_list.front()->my_place);
		delete this->_sorted_list.front();
		this->_sorted_list.pop_front();
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << this->duration_deque << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << this->duration_list << " us" << std::endl;
}

template <typename T>
static T find_pos(T start_it, T end_it, block *ptr)
{
	if (ptr == NULL)
		return (start_it);
	while (start_it != end_it)
	{
		typename std::iterator_traits<T>::difference_type dist = std::distance(start_it, end_it); //find the type of iterator and calculate the range between start_it and end_it
		T mid = start_it;
		std::advance(mid, dist / 2); // move mid to dist/n pos
		
		if (ptr->value <= (*mid)->value)
			end_it = mid;
		else
		{
			start_it = mid;
			++start_it;
		}
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
		//stack_final.insert(*stack.begin());
		typename T::iterator inserted_it = stack_final.insert(stack_final.begin(), *stack.begin());
		(*stack_final.begin())->my_place = static_cast<void*>(new typename T::iterator(inserted_it));
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
			(*it)->pair = *next;
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
		if ((*it)->pair != NULL && (*it)->pair->my_place != NULL) //in case where it's NULL
		{
			std::cout << "oui" << std::endl;
			std::cout << "oui value= " << (*it)->value << std::endl;
			up_it = *static_cast<typename T::iterator*>((*it)->pair->my_place);
		}
		else
		{
			std::cout << "coucou: value= " << (*it)->value;
			if ((*it)->pair)
				std::cout << ", pair=" << (*it)->pair->value;
			if ((*it)->pair->my_place)
				std::cout << ", pair->myplace =" << (*it)->pair->my_place;
			else
				std::cout << "PAIR MYPLACE = NULL" << std::endl;

			//std::cout << ", stack_final.size=" << stack_final.size() << std::endl;
			up_it = stack_final.end();
		}
		typename T::iterator insert_pos = find_pos(stack_final.begin(), up_it, *it);
		
		//?Old 
		//(*it)->my_place = static_cast<void*>(new typename T::iterator(stack_final.insert(insert_pos, *it)));
		//! l'iterateur d'où je suis dans stack_final = l'iterator renvoyer par insert

		// //?new
		if ((*it)->my_place)
			delete static_cast<typename T::iterator*>((*it)->my_place);

		typename T::iterator inserted_it = stack_final.insert(insert_pos, *it);

		(*it)->my_place = static_cast<void*>(new typename T::iterator(inserted_it));

		// Debug
		std::cout << "Inserted value=" << (*it)->value << " at position, my_place updated." << std::endl;
	}
}

