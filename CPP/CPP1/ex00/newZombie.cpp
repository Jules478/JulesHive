#include "Zombie.hpp"

Zombie* newZombie(str name)
{
	Zombie* zombie = new Zombie;
	zombie->setName(name);
	return zombie;
}