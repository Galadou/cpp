#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	//initialize inventory of 'me'
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		me->equip(tmp);
	}

	//use all materia handle by 'me' (print)
	ICharacter* bob = new Character("bob");
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);
	
	//trying to equipe a Materia when inventory is full (print nothing)
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	//Double unequip slot 0, for check the error of unequip
	me->unequip(0);
	me->unequip(0);

	//Delete all allocated instance.
	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}