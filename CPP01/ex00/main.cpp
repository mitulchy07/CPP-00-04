#include "Zombie.hpp"

int	main(void)
{
	Zombie	stackZombie("StackZombie");

	stackZombie.announce();

	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("RandomZombie");

	return (0);
}
