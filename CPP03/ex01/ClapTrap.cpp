#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << this->name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap " << this->name << " assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and dies!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! (" << hitPoints << " HP left)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't be repaired!" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points! (" << hitPoints << " HP now)" << std::endl;
}
