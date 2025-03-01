#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

//on dis quil faut donner un type qu'on va pour l'instant appeler 'T'
template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;
	public:
		Array() : _size(0), _array(NULL) {}
		~Array() {delete[] _array;} 
		Array(unsigned int n) : _size(n) {_array = new T[n]();} //!MAYDAY SUJET NEW[] ??
		Array(Array const &src) {*this = src;}
		unsigned int size() const {return (this->_size);}
		//l'operateur = fais bien une deep copy.
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
		//l'operateur [] permet d'acceder a une case de notre array.
		//il renvoie un 'T'& (la référence est obligatoire pour pouvoir modifié la case.)
		//il renvoie une exeption out of range comme demandé par le sujet.
		//avec lui, on va pouvoir print une case, ou meme modifié une case (a voir dans le main)
		T	&operator[](unsigned int index)
		{
			if (index < 0 || index > _size - 1)
				throw std::out_of_range("Error: index is out of range.");
			return (_array[index]);
		}
};


#endif