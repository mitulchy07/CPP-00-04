#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Creating a FragTrap ===" << std::endl;
	FragTrap frag("FR-4G");

	std::cout << "\n=== Testing FragTrap attack ===" << std::endl;
	frag.attack("enemy");
	frag.attack("enemy");

	std::cout << "\n=== Testing FragTrap takeDamage ===" << std::endl;
	frag.takeDamage(30);
	frag.takeDamage(50);

	std::cout << "\n=== Testing FragTrap beRepaired ===" << std::endl;
	frag.beRepaired(20);

	std::cout << "\n=== Testing FragTrap special ability ===" << std::endl;
	frag.highFivesGuys();
	frag.highFivesGuys();

	std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
	{
		FragTrap temp("FragTempBot");
	}

	std::cout << "\n=== Testing with ScavTrap for comparison ===" << std::endl;
	ScavTrap scav("SC-4V");
	scav.attack("target");
	frag.attack("target");
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n=== Exiting ===" << std::endl;
	return 0;
}
