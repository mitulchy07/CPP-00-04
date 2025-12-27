#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Creating a DiamondTrap ===" << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << "\n=== Testing whoAmI() ===" << std::endl;
	diamond.whoAmI();

	std::cout << "\n=== Testing attack (from ScavTrap) ===" << std::endl;
	diamond.attack("enemy");
	diamond.attack("enemy");

	std::cout << "\n=== Testing takeDamage ===" << std::endl;
	diamond.takeDamage(30);
	diamond.takeDamage(50);

	std::cout << "\n=== Testing beRepaired ===" << std::endl;
	diamond.beRepaired(20);

	std::cout << "\n=== Testing special abilities ===" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
	{
		DiamondTrap temp("TempDiamond");
		temp.whoAmI();
	}

	std::cout << "\n=== Testing copy and assignment ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();

	std::cout << "\n=== Exiting ===" << std::endl;
	return 0;
}
