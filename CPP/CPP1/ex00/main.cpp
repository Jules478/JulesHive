#include "Zombie.hpp"

int main()
{
	Zombie zombie1;
	zombie1.setName("Shaun");
	Zombie* zombie2 = newZombie("Ed");

	zombie1.announce();
	zombie2->announce();

	delete zombie2;

	randomChump("Phil");
	return 0;
}