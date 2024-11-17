#include "Zombie.hpp"
#include <iostream>
Zombie *zombieHorde( int N, std::string name )
{
	Zombie *horde = NULL;

	horde = new Zombie [N];

	for (int i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);
	}
	return (horde);
}