#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iterator>

//!debug
#include <vector>


struct block
{
	int value;
	block *pair;

	size_t my_place;
};

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
		std::deque<block *>					_deque_number;
		std::deque<block *> 					_sorted_deque;
		double duration_deque;
		bool								last_number;
		// std::list<block *>						_list_number;
		// std::list<block *> 						_sorted_list;
		// double duration_list;
		
		//test
		std::vector<block *>						_vector_number;
		std::vector<block *> 						_sorted_vector;
		double duration_vector;
};

template <typename T>
void	fordJohnson(T &stack, T &stack_final);


#endif