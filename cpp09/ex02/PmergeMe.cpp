#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	last_number = false;
	parsing(argc, argv);
}
PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		//here
	}
	return *this;
}

void PmergeMe::parsing(int argc, char **argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error: Not enought param.");
	if (argc > 5000)
		throw std::invalid_argument("Error: too much param.");
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == NULL || strlen(argv[i]) == 0) // check if argv[i] is null or empty
			throw std::invalid_argument("Error: empty or null argument.");
		if (isdigit(argv[i][0]) == false) // its not a number
			throw std::invalid_argument("Error: bad operator sign (should be +-*/).");
		long int nb = std::atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			throw std::invalid_argument("Error: number out of range.");
		this->_deque_number.push_back(nb);
	}
}

void	PmergeMe::stock_deque_to_pair()
{
	std::pair<int, int> pair_buffer;

	if (this->_deque_number.size() == 1)
		return ; //!Result direct
	if (this->_deque_number.size() == 2)
	{
		if (this->_deque_number[0] > this->_deque_number[1])
			std::swap(this->_deque_number[0], this->_deque_number[1]);
		return ;//!Result direct
	}
	for ((void)_deque_number; _deque_number.size() > 0; (void)_deque_number)
	{
		if (this->_deque_number.size() == 1)
		{
			this->last_number = true; //!ne pas oublier
			return ;
		}
		pair_buffer.first = this->_deque_number.front(); //stock the first number
		this->_deque_number.pop_front(); //remove the first number from the deque
		pair_buffer.second = this->_deque_number.front(); //stock the second number
		this->_deque_number.pop_front(); //remove the second number from the deque
		if (pair_buffer.first > pair_buffer.second)
			std::swap(pair_buffer.first, pair_buffer.second); //?swap the two numbers in the pair container
		this->_deque_pair.push_back(pair_buffer);
	}
}

void	PmergeMe::sort_bigger()
{
	std::deque<std::pair<int, int> >::iterator it;
	std::deque<std::pair<int, int> >::iterator it_last_max;
	int	last_max_found = 0;

	if (this->_deque_pair.empty())
		return ;
	if (this->_deque_pair.size() == 1)
	{
		this->_sorted_deque.push_back(this->_deque_pair.begin()->second);
		return;
	}
	while (this->_deque_pair.size() > 1)
	{
		last_max_found = this->_deque_pair.begin()->second;
		it_last_max = this->_deque_pair.begin(); //initialisation du premier lien
		for (it = this->_deque_pair.begin() + 1; it != this->_deque_pair.end(); it++) //est initialise au deuxieme
		{
			if (it->second < last_max_found)
			{
				it_last_max = it;
				last_max_found = it->second;
			}
		}
		this->_pair_sort_bigger.push_back(*it);
		this->_deque_pair.erase(it_last_max); //on erase celui qui viens detre trier
	}
	this->_pair_sort_bigger.push_back(*this->_deque_pair.begin());
	this->_deque_pair.erase(this->_deque_pair.begin());
	for (it = this->_pair_sort_bigger.begin(); it != this->_pair_sort_bigger.end(); it++) //on stock tout les plus grand dans sorted
		this->_sorted_deque.push_back(it->second);
}

void	PmergeMe::sort_smaller()
{
	std::deque<std::pair<int, int> >::iterator it_pair;
	std::deque<int>::iterator it_sorted;

	if (this->_pair_sort_bigger.empty())
		return ;
	if (this->_deque_pair.size() == 1)
	{
		this->_sorted_deque.push_front(this->_deque_pair.begin()->first); // on met le plus petit devant
		return;
	}
	for (it_pair = this->_pair_sort_bigger.begin(); it_pair != this->_pair_sort_bigger.end(); it_pair++)
	{
		it_sorted = this->_sorted_deque.begin();
		while (it_sorted != this->_sorted_deque.end() && *it_sorted < it_pair->first)
			it_sorted++;
		this->_sorted_deque.insert(it_sorted, it_pair->first);
	} //normalement ils sont tous trier dans sorted deque

	if (this->last_number == true)
	{
		it_sorted = this->_sorted_deque.begin();
		while (it_sorted != this->_sorted_deque.end() && *it_sorted < *this->_deque_number.begin()) //si il restais un truc dedans, on le tri
			it_sorted++;
		this->_sorted_deque.insert(it_sorted, *this->_deque_number.begin());
	}
}

void	PmergeMe::print_value()
{

}

