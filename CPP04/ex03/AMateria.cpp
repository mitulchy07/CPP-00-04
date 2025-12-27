#include "AMateria.hpp"

AMateria::AMateria() : type("")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		// Don't copy the type according to the requirement
		// type = other.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}
