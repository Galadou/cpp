
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap robot("Bla");

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(10);
	robot.attack("José");
}