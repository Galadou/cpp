#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout << "Copy constructor of MateriaSource called." << std::endl;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "Copy assignment of MateriaSource operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* src) 
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = src;
			return;
		}
	}
	delete src;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && type == this->_inventory[i]->getType())
			return (this->_inventory[i]->clone());
	}
	return (0);
}