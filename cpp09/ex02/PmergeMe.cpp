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
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (isdigit(argv[i][j]) == false) // its not a number
				throw std::invalid_argument("Error: bad operator sign.");
		}
		long int nb = std::atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			throw std::invalid_argument("Error: number out of range.");
		this->_deque_number.push_back(nb);
	}
}

void	PmergeMe::exec()
{
	//deque
	//We stock the value to pair, first is the smaller, second the bigger between the pair
	this->stock_deque_to_pair(this->_deque_number, this->_deque_pair);
	this->sort_bigger(this->_deque_pair, this->_pair_sort_bigger, this->_sorted_deque);
	this->sort_smaller(this->_deque_pair, this->_pair_sort_bigger, this->_sorted_deque); //! a faire changement

	//list
	this->stock_deque_to_pair(this->_list_number, this->_list_pair);
	this->sort_bigger(this->_list_pair, this->_lst_pair_sort_bigger, this->_sorted_list);

}

template <typename T, typename N>
void	PmergeMe::stock_deque_to_pair(T &container, N &cont_pair) // a clean les deque
{
	std::pair<int, int> pair_buffer;

	if (container.size() == 1)
		return ; //!Result direct
	if (container.size() == 2)
	{
		if (container.front() > container.back())
			std::swap(container.front(), container.back());
		return ;//!Result direct
	}
	for ((void)container; container.size() > 0; (void)container)
	{
		if (container.size() == 1)
		{
			this->last_number = true; //!ne pas oublier
			return ;
		}
		pair_buffer.first = container.front(); //stock the first number
		container.pop_front(); //remove the first number from the deque
		pair_buffer.second = container.front(); //stock the second number
		container.pop_front(); //remove the second number from the deque
		if (pair_buffer.first > pair_buffer.second)
			std::swap(pair_buffer.first, pair_buffer.second); //?swap the two numbers in the pair container
		cont_pair.push_back(pair_buffer);
	}
}

template <typename T, typename N>
void	PmergeMe::sort_bigger(T &container_pair, T &pair_sort_bigger, N &sorted_cont)
{
	typename T::iterator it;
	typename T::iterator it_last_max;
	int	last_max_found = 0;

	if (container_pair.empty())
		return ;
	if (container_pair.size() == 1)
	{
		sorted_cont.push_back(container_pair.begin()->second);
		return;
	}
	while (container_pair.size() > 1)
	{
		last_max_found = container_pair.begin()->second;
		it_last_max = container_pair.begin(); //initialisation du premier lien
		for (it = ++container_pair.begin(); it != container_pair.end(); it++) //est initialise au deuxieme
		{
			if (it->second < last_max_found)
			{
				it_last_max = it;
				last_max_found = it->second;
			}
		}
		pair_sort_bigger.push_back(*it_last_max); //? avant cetais ca : pair_sort_bigger.push_back(*it);
		container_pair.erase(it_last_max); //on erase celui qui viens detre trier
	}
	pair_sort_bigger.push_back(*container_pair.begin());
	container_pair.erase(container_pair.begin());
	for (it = pair_sort_bigger.begin(); it != pair_sort_bigger.end(); it++) //on stock tout les plus grand dans sorted
		sorted_cont.push_back(it->second);
}

template <typename T, typename N>
void	PmergeMe::sort_smaller(T &container_pair, T &pair_sort_bigger, N &sorted_cont)
{
	typename T::iterator it_pair;
	typename N::iterator it_sorted;

	if (pair_sort_bigger.empty())
		return ;
	if (container_pair.size() == 1)
		sorted_cont.push_front(container_pair.begin()->first); // on met le plus petit devant
	else
	{
		for (it_pair = pair_sort_bigger.begin(); it_pair != pair_sort_bigger.end(); it_pair++)
		{
			it_sorted = sorted_cont.begin();
			while (it_sorted != sorted_cont.end() && *it_sorted < it_pair->first)
				it_sorted++;
			sorted_cont.insert(it_sorted, it_pair->first);
		} //normalement ils sont tous trier dans sorted deque
	}
	if (this->last_number == true)
	{
		it_sorted = sorted_cont.begin();
		while (it_sorted != sorted_cont.end() && *it_sorted < *this->_deque_number.begin()) //si il restais un truc dedans, on le tri
			it_sorted++;
		sorted_cont.insert(it_sorted, *this->_deque_number.begin());
	}
}

void	PmergeMe::print_value()
{

}

