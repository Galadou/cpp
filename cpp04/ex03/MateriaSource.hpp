#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		//cpy
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *_inventory[4];
};

#endif