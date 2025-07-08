#include "Zombie.hpp"

void randomChump(str name)
{
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}