
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::string str = "Jules";
	ScavTrap robot(str);

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(50);
	robot.attack("José");
}