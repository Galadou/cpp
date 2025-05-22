#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iterator>

//!  file:///nfs/homes/gmersch/Downloads/Merge_Insertion_sort%20(3).pdf

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

		template <typename T>
		void parsing(int argc, char **argv, T &container);

		void	exec();

		void	print_value(int argc, char **argv);

	private:
		std::deque<int>					_deque_number;
		std::deque<int> 					_sorted_deque;
		double duration_deque;
		bool								last_number;
		std::list<int>						_list_number;
		std::list<int> 						_sorted_list;
		double duration_list;
};

template <typename T>
T fordJohnson(T &stack);





#endif