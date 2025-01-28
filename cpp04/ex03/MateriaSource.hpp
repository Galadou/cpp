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
		MateriaSource(MateriaSource const &src);
		MateriaSource	&operator=(const MateriaSource &src);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *_inventory[4];
};

#endif