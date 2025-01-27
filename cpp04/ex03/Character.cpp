#include "Character.hpp"

//Default constructor
Character::Character(const std::string name) : _idx(0), _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_ground[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_ground[i] != NULL)
			delete this->_ground[i];
	}
}


Character::Character(Character const &src)
{
	std::cout << "Copy constructor of Character called." << std::endl;
	*this = src;
}

Character	&Character::operator=(const Character &src)
{
	std::cout << "Copy assignment of Character operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] =  src._inventory[i];
		}
		for (int i = 0; i < 100; i++)
		{
			if (this->_ground[i] != NULL)
				delete this->_ground[i];
			this->_ground[i] =  src._ground[i];
		}
		this->_idx = src._idx;
		*this->_inventory = *src._inventory;
		this->_name = src._name;
	}
	return (*this);
}


std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	int	i;
	
	if (idx < 4 && this->_inventory[idx] != NULL)
	{
		i = 0;
		for (i = 0; this->_ground[i]; i++) {}
		if (i < 100)
			this->_ground[i] =  this->_inventory[idx];
		else
		{
			std::cout << "Cannot unequip " << this->_name << ", no place in ground" << std::endl;
			return;
		}
		this->_inventory[idx] = NULL;
	}
	std::cout << "Already no Materia in hand" << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}