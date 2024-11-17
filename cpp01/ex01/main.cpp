#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int N = 10;
	Zombie *horde = zombieHorde(N, "OUI");

	int i = 0;
	while (i < N)
	{
		horde[i].announce();
	}
	return (0);
}