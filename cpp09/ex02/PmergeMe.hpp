#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <list>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

		void	parsing(int argc, char **argv);
		void	exec();

		template <typename T, typename N>
		void	stock_deque_to_pair(T &container, N &cont_pair);
		template <typename T, typename N>
		void	sort_bigger(T &container_pair,T &_pair_sort_bigger, N &sorted_cont);
		template <typename T>
		void	sort_smaller();
		void	print_value();


		// void	getDequeNumber() const;
		// void	getDequePair() const;
		// void	getPairSortBigger() const;
		// void	getSortedDeque() const;
		// void	getDequeNumber() const;

	private:
		std::deque<int>						_deque_number;
		std::deque<std::pair<int, int> >	_deque_pair;
		std::deque<std::pair<int, int> >	_pair_sort_bigger;
		std::deque<int> 					_sorted_deque;
		bool								last_number;
		std::list<int>						_list_number;
		std::list<std::pair<int, int> >		_list_pair;
		std::list<std::pair<int, int> >		_lst_pair_sort_bigger;
		std::list<int> 						_sorted_list;
};





#endif