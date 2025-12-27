#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	ClapTrap::hitPoints = 100;
	ClapTrap::energyPoints = 100;
	ClapTrap::attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (ClapTrap::hitPoints == 0)
	{
		std::cout << "FragTrap is dead and can't attack!" << std::endl;
		return;
	}
	if (ClapTrap::energyPoints == 0)
	{
		std::cout << "FragTrap has no energy points left to attack!" << std::endl;
		return;
	}
	ClapTrap::energyPoints--;
	std::cout << "FragTrap attacks " << target << ", causing " << ClapTrap::attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap enthusiastically requests high-fives from everyone! ✋" << std::endl;
}
