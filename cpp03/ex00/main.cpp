
#include "ClapTrap.hpp"

int main(void)
{
	std::string name = "Bla";
	ClapTrap robot(name);

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(10);
	robot.attack("José");
	robot.beRepaired(2);
}