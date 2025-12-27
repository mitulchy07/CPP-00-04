#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		templates[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
		{
			templates[i] = other.templates[i]->clone();
		}
		else
		{
			templates[i] = 0;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// Delete old templates
		for (int i = 0; i < 4; i++)
		{
			if (templates[i])
			{
				delete templates[i];
				templates[i] = 0;
			}
		}
		// Copy new templates
		for (int i = 0; i < 4; i++)
		{
			if (other.templates[i])
			{
				templates[i] = other.templates[i]->clone();
			}
			else
			{
				templates[i] = 0;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i])
		{
			delete templates[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	
	for (int i = 0; i < 4; i++)
	{
		if (!templates[i])
		{
			templates[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
		{
			return templates[i]->clone();
		}
	}
	return 0;
}
