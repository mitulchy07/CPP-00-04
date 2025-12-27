#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== Creating a ScavTrap ===" << std::endl;
	ScavTrap scav("ST-4R");

	std::cout << "\n=== Testing ScavTrap attack ===" << std::endl;
	scav.attack("enemy");
	scav.attack("enemy");

	std::cout << "\n=== Testing ScavTrap takeDamage ===" << std::endl;
	scav.takeDamage(30);
	scav.takeDamage(50);

	std::cout << "\n=== Testing ScavTrap beRepaired ===" << std::endl;
	scav.beRepaired(20);

	std::cout << "\n=== Testing ScavTrap special ability ===" << std::endl;
	scav.guardGate();
	scav.guardGate();

	std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
	{
		ScavTrap temp("Temporary");
	}

	std::cout << "\n=== Exiting ===" << std::endl;
	return 0;
}
