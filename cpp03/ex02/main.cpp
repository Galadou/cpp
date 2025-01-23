
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string name = "Jules";
	FragTrap robot(name);

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(10);
	robot.attack("José");
	robot.highFivesGuys();
	robot.takeDamage(100);
	robot.attack("José");
	robot.highFivesGuys();
}