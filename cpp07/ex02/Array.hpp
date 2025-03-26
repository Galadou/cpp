#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

//we say that we must give a type that we will call 'T' for the moment
template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;
	public:
		Array() : _size(0), _array(NULL) {}
		~Array() {delete[] _array;} 
		Array(unsigned int n) : _size(n)
		{
			if (n < 1)
				throw std::invalid_argument("Error: Invalid size given.");
			_array = new T[n]();
		}
		Array(Array const &src) {*this = src;}
		unsigned int size() const {return (this->_size);}
		Array *operator=(Array const &src)
		{
			if (this != &src)
			{
				if (_array)
					delete[] _array;
				_array = new T[src.size()]();
				_size = src._size;
				for (int i = 0; i < src.size(); i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}
		T	&operator[](unsigned int index)
		{
			if (index < 0 || index > _size - 1)
				throw std::out_of_range("Error: index is out of range.");
			return (_array[index]);
		}
};


#endif
