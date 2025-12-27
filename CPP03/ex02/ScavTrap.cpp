#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	ClapTrap::hitPoints = 100;
	ClapTrap::energyPoints = 50;
	ClapTrap::attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (ClapTrap::hitPoints == 0)
	{
		std::cout << "ScavTrap is dead and can't attack!" << std::endl;
		return;
	}
	if (ClapTrap::energyPoints == 0)
	{
		std::cout << "ScavTrap has no energy points left to attack!" << std::endl;
		return;
	}
	ClapTrap::energyPoints--;
	std::cout << "ScavTrap attacks " << target << ", causing " << ClapTrap::attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode!" << std::endl;
}
