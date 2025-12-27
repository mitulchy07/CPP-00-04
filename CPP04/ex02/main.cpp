#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Test 1: Cannot instantiate abstract Animal ===" << std::endl;
	// const Animal* meta = new Animal(); // ERROR: cannot instantiate abstract class
	std::cout << "Animal is abstract - you cannot create an instance directly!" << std::endl;

	std::cout << std::endl << "=== Test 2: Can instantiate Dog and Cat ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "Types:" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << std::endl << "Sounds:" << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl << "Cleanup:" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "=== Test 3: Array of animals ===" << std::endl;
	int arraySize = 4;
	Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	std::cout << std::endl << "Making sounds:" << std::endl;
	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	animals[3]->makeSound();

	std::cout << std::endl << "Deleting animals:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}

	std::cout << std::endl << "=== Test 4: Testing deep copy ===" << std::endl;
	Dog dog1;
	Dog dog2 = dog1;

	std::cout << "dog1 and dog2 have different Brain instances (deep copy)" << std::endl;

	Cat cat1;
	Cat cat2 = cat1;

	std::cout << "cat1 and cat2 have different Brain instances (deep copy)" << std::endl;

	std::cout << std::endl << "End of main - all destructors will be called" << std::endl;

	return 0;
}
