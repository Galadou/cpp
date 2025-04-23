#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

		void	parsing(int argc, char **argv);
		void	stock_deque_to_pair();
		void	sort_bigger();
		void	sort_smaller();

	private:
		std::deque<int>						_deque_number;
		std::deque<std::pair<int, int> >	_deque_pair;
		std::deque<std::pair<int, int> >	_pair_sort_bigger;
		std::deque<int> 					_sorted_deque;
		bool								last_number;
};


#endif