#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Basic Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* ice_template = new Ice();
	AMateria* cure_template = new Cure();
	src->learnMateria(ice_template);
	src->learnMateria(cure_template);
	delete ice_template;
	delete cure_template;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "=== Additional Tests ===" << std::endl;

	std::cout << std::endl << "Test 1: Multiple materias of same type" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	AMateria* ice_t1 = new Ice();
	AMateria* ice_t2 = new Ice();
	AMateria* cure_t = new Cure();
	src2->learnMateria(ice_t1);
	src2->learnMateria(ice_t2);
	src2->learnMateria(cure_t);
	delete ice_t1;
	delete ice_t2;
	delete cure_t;
	ICharacter* alice = new Character("alice");
	
	for (int i = 0; i < 4; i++)
	{
		AMateria* mat = src2->createMateria("ice");
		if (mat)
			alice->equip(mat);
	}
	
	ICharacter* charlie = new Character("charlie");
	alice->use(0, *charlie);
	alice->use(1, *charlie);
	alice->use(2, *charlie);
	alice->use(3, *charlie);
	
	delete charlie;
	delete alice;
	delete src2;

	std::cout << std::endl << "Test 2: Copy constructor" << std::endl;
	Character char1("hero");
	char1.equip(new Ice());
	char1.equip(new Cure());
	
	Character char2(char1);
	Character char3 = char1;
	
	ICharacter* target = new Character("dummy");
	char1.use(0, *target);
	char2.use(0, *target);
	char3.use(0, *target);
	
	delete target;

	std::cout << std::endl << "Test 3: Unequip" << std::endl;
	Character fighter("fighter");
	AMateria* fire = new Ice();
	fighter.equip(fire);
	fighter.equip(new Cure());
	
	ICharacter* enemy = new Character("enemy");
	fighter.use(0, *enemy);
	fighter.use(1, *enemy);
	fighter.unequip(0);
	fighter.use(0, *enemy); // should do nothing
	
	delete enemy;
	// Note: unequip doesn't delete, so fire would need to be manually deleted
	// but to avoid memory leak we'll delete it
	delete fire;

	std::cout << std::endl << "Test 4: Unknown materia type" << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	AMateria* unknown = src3->createMateria("unknown");
	if (unknown == 0)
		std::cout << "Unknown materia returns 0 (null pointer)" << std::endl;
	delete src3;

	std::cout << std::endl << "All tests completed" << std::endl;

	return 0;
}
