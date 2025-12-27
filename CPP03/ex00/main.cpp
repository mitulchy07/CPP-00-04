#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Creating a ClapTrap ===" << std::endl;
	ClapTrap trap("CR-8D");

	std::cout << "\n=== Testing attack ===" << std::endl;
	trap.attack("enemy");
	trap.attack("enemy");

	std::cout << "\n=== Testing takeDamage ===" << std::endl;
	trap.takeDamage(3);
	trap.takeDamage(5);
	trap.takeDamage(5);

	std::cout << "\n=== Testing beRepaired ===" << std::endl;
	trap.beRepaired(5);
	trap.beRepaired(3);

	std::cout << "\n=== Testing energy depletion ===" << std::endl;
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");
	trap.attack("enemy");

	std::cout << "\n=== Testing after energy is gone ===" << std::endl;
	trap.beRepaired(5);

	std::cout << "\n=== Testing dead trap ===" << std::endl;
	ClapTrap dead("R2-D2");
	dead.takeDamage(20);
	dead.attack("enemy");
	dead.beRepaired(10);

	std::cout << "\n=== Exiting ===" << std::endl;
	return 0;
}
