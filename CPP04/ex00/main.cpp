#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Animal, Dog, Cat with virtual functions ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "Types:" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << std::endl << "Sounds:" << std::endl;
	i->makeSound(); // cat sound
	j->makeSound(); // dog sound
	meta->makeSound(); // animal sound

	std::cout << std::endl << "Cleanup correct classes:" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "=== Testing WrongAnimal and WrongCat (no virtual) ===" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl << "WrongCat type: " << wrong_cat->getType() << std::endl;

	std::cout << std::endl << "Sounds (note: both will use WrongAnimal::makeSound):" << std::endl;
	wrong_cat->makeSound(); // will call WrongAnimal::makeSound (not virtual)
	wrong_meta->makeSound();

	std::cout << std::endl << "Cleanup wrong classes:" << std::endl;
	delete wrong_meta;
	delete wrong_cat;

	std::cout << std::endl << "=== Testing copy constructors and assignment ===" << std::endl;
	Dog dog1;
	Dog dog2 = dog1;
	Dog dog3;
	dog3 = dog1;

	Cat cat1;
	Cat cat2 = cat1;

	std::cout << std::endl << "End of main - destructors will be called" << std::endl;

	return 0;
}
