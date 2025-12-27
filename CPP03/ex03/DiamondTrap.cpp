#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : FragTrap(name), ScavTrap(name), name(name)
{
	ClapTrap::name = name + "_clap_name";
	ClapTrap::hitPoints = 100;		// from FragTrap
	ClapTrap::energyPoints = 50;	// from ScavTrap
	ClapTrap::attackDamage = 30;	// from FragTrap
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	FragTrap::operator=(other);
	this->name = other.name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
