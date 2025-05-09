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
		this->_deque_pair = src._deque_pair;
		this->_pair_sort_bigger = src._pair_sort_bigger;
		this->_sorted_deque = src._sorted_deque;
		this->duration_deque = src.duration_deque;
		this->last_number = src.last_number;
		this->_list_number = src._list_number;
		this->_list_pair = src._list_pair;
		this->_lst_pair_sort_bigger = src._lst_pair_sort_bigger;
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
	this->stock_container_to_pair(this->_deque_number, this->_deque_pair);
	this->sort_bigger(this->_deque_pair, this->_pair_sort_bigger, this->_sorted_deque);
	this->sort_smaller(this->_deque_pair, this->_pair_sort_bigger, this->_sorted_deque, this->_deque_number);
	std::clock_t end_time = std::clock();
	this->duration_deque = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;


	//list
	start_time = std::clock();
	this->stock_container_to_pair(this->_list_number, this->_list_pair);
	this->sort_bigger(this->_list_pair, this->_lst_pair_sort_bigger, this->_sorted_list);
	this->sort_smaller(this->_list_pair, this->_lst_pair_sort_bigger, this->_sorted_list, this->_list_number);
	end_time = std::clock();
	this->duration_list = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

}

template <typename T, typename N>
void	PmergeMe::stock_container_to_pair(T &container, N &cont_pair)
{
	std::pair<int, int> pair_buffer;

	for ((void)container; container.size() > 0; (void)container)
	{
		if (container.size() == 1)
		{
			this->last_number = true;
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
	while (container_pair.size() > 1)
	{
		last_max_found = container_pair.begin()->second;
		it_last_max = container_pair.begin();
		for (it = ++container_pair.begin(); it != container_pair.end(); it++)
		{
			if (it->second < last_max_found)
			{
				it_last_max = it;
				last_max_found = it->second;
			}
		}
		pair_sort_bigger.push_back(*it_last_max);
		container_pair.erase(it_last_max);
	}
	pair_sort_bigger.push_back(*container_pair.begin());
	container_pair.erase(container_pair.begin());
	for (it = pair_sort_bigger.begin(); it != pair_sort_bigger.end(); it++)
		sorted_cont.push_back(it->second);
}

template <typename T, typename N>
void	PmergeMe::sort_smaller(T &container_pair, T &pair_sort_bigger, N &sorted_cont, N &container)
{
	typename T::iterator it_pair;
	typename N::iterator it_sorted;

	if (pair_sort_bigger.empty())
	{
		if (this->last_number == true)
		{
			sorted_cont.push_back(container.front());
			container.erase(container.begin());
		}
		return ;
	}
	if (container_pair.size() == 1)
		sorted_cont.push_front(container_pair.begin()->first);
	else
	{
		for (it_pair = pair_sort_bigger.begin(); it_pair != pair_sort_bigger.end(); it_pair++)
		{
			it_sorted = sorted_cont.begin();
			while (it_sorted != sorted_cont.end() && *it_sorted < it_pair->first)
				it_sorted++;
			sorted_cont.insert(it_sorted, it_pair->first);
		}
	}
	if (this->last_number == true)
	{
		it_sorted = sorted_cont.begin();
		while (it_sorted != sorted_cont.end() && *it_sorted < *container.begin())
			it_sorted++;
		sorted_cont.insert(it_sorted, container.front());
	}
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

template <typename T> //! je cherche toujours a mettre nb AVANT l'iterator qui sera return
typename T::iterator find_pos(T::iterator &start_it, TT::iterator &end_it, int nb)
{
	T::iterator it_mid;
	T::iterator pos_final;


	int dist = end_it - start_it;
	it_mid = start_it + (dist / 2);
	if (it_mid == start_it || it_mid == end_it)
	{
		if (nb < start_it)
			return (start_it)
		if (nb > start_it && nb < end_it)
			return 
	}
	if (nb < *it_mid)//jenvoie meme start mais mid pour end
		pos_final = find_pos(start_it, it_mid, nb);
	else if (nb > *it_mid && nb > *it_mid + 1) // plus grand que celui la mais aussi plus grand aue celui d'apres


}

template <typename T, typename N>
T &fordJohnson(T &stack)
{
	T stack_smaller;
	T stack_bigger;
	T stack_final;
	int size = stack.size();

	if (size < 2) // si il n'y a q'un element, donc le plus grand, on return
		return (stack);
	N stack_pair;
	//en gros je decoupe la chaine de nombre 2 par 2 : le plus petit des deux va dans la case first, le plus grand va dans la case second.
	for (int i = 0; i + 1 < size; i += 2) // a revoir, +1 je suis pas sur
	{
		if ()
		if (stack[i] < stack[i + 1])
			stack_pair.push_back(std::make_pair(stack[i], stack[i + 1]));
		else
			stack_pair.push_back(std::make_pair(stack[i + 1], stack[i]));
	}
	if (size %2 != 0) // si c'etais impaire, il doit rester un truc dedans donc on le met dans les plus grand
		stack_bigger.push_back(stack[size - 1]);

	//je met tout les premier dans la stack petite, et les second dans la stack grand
	for (; !stack_pair.empty(); stack_pair.erase(stack_pair.begin()))
	{
		stack_smaller.push_back(stack_pair->first);
		stack_bigger.push_back(stack_pair->second);
	}

	stack_final = fordJohnson(stack_bigger);

	for (; !stack_smaller.empty(); stack_smaller.erase(stack_smaller.begin()))
	{

		stack_final.insert() stack_smaller.begin()
	}

	return (stack_final);




}




































// // Fonction pour insérer un élément dans un vecteur trié
// void insert_sorted(std::vector<int>& sorted, int value)
// {
// 	std::vector<int>::iterator it = sorted.begin();
// 	while (it != sorted.end() && *it < value)
// 		++it;
// 	sorted.insert(it, value);
// }

// // Fonction récursive Ford-Johnson (C++98)
// std::vector<int> ford_johnson_sort(const std::vector<int>& input)
// {
// 	size_t n = input.size();
// 	if (n <= 1)
// 		return input;

// 	std::vector<std::pair<int, int> > pairs;
// 	std::vector<int> small;
// 	std::vector<int> large;

// 	// Création des paires
// 	size_t i = 0;
// 	for (; i + 1 < n; i += 2)
// 	{
// 		int a = input[i];
// 		int b = input[i + 1];
// 		if (a < b)
// 			pairs.push_back(std::make_pair(a, b));
// 		else
// 			pairs.push_back(std::make_pair(b, a));
// 	}

// 	// Séparer en deux listes : petits et grands
// 	for (size_t j = 0; j < pairs.size(); ++j) {
// 		small.push_back(pairs[j].first);
// 		large.push_back(pairs[j].second);
// 	}

// 	// Si impair, ajouter le dernier élément aux grands
// 	if (n % 2 != 0)
// 		large.push_back(input.back());

// 	// Récursivité sur les grands
// 	std::vector<int> sorted = ford_johnson_sort(large);

// 	// Insertion des petits dans la liste triée
// 	for (size_t k = 0; k < small.size(); ++k) {
// 		insert_sorted(sorted, small[k]);
// 	}

// 	return sorted;
// }


