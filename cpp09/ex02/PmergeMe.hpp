#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <ctime>
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
		std::deque<block *>		_deque_number;
		std::deque<block *>		_sorted_deque;
		double					duration_deque;
		std::deque<size_t>		jacobsthal_deque;
		bool					last_number;
		
		std::vector<block *>	_vector_number;
		std::vector<block *>	_sorted_vector;
		double					duration_vector;
		std::deque<size_t>		jacobsthal_vector;
};

template <typename T, typename N>
void	fordJohnson(T &stack, T &stack_final, N jacobsthal);

#endif