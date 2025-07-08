#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard(false)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_dmg = 20;
	std::cout << GREEN << this->_name << RESET << " rolled out of the factory." << std::endl;
}

ScavTrap::ScavTrap(str name) : ClapTrap(name), _guard(false)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_dmg = 20;

	std::cout << GREEN << this->_name << RESET << " rolled out of the factory." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& guy) : ClapTrap(guy), _guard(false)
{
	this->_name = guy._name;
	this->_hp = guy._hp;
	this->_ep = guy._ep;
	this->_dmg = guy._dmg;
	std::cout << GREEN << this->_name << RESET << " copied another ScavTrap." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& guy)
{
	if (this != &guy)
	{
		this->_name = guy._name;
		this->_hp = guy._hp;
		this->_ep = guy._ep;
		this->_dmg = guy._dmg;
		this->_guard = guy._guard;
	}
	std::cout << GREEN << this->_name << RESET << " equals another ScavTrap." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN << this->_name << RESET << " went to the scrapyard." << std::endl;
}

void ScavTrap::attack(const str& target)
{
	if (this->_hp == 0)
		std::cout << GREEN << this->_name << RESET << " cannot attack because it is dead." << std::endl;
	else if (this->_ep > 0)
	{
		this->_ep--;
		std::cout << GREEN << this->_name << RESET << " damaged " << target << ", causing " << this->_dmg << " points of damage!" << std::endl;
	}
	else
		std::cout << GREEN << this->_name << RESET << " has no energy to attack right now." << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_hp == 0 && this->_guard == false)
		std::cout << GREEN << this->_name << RESET << " cannot guard the gate because it is dead." << std::endl;
	else if (this->_hp == 0 && this->_guard == true)
		std::cout << GREEN << this->_name << RESET << " cannot stop guarding the gate because it is dead." << std::endl;
	else if (this->_guard == false)
	{
		std::cout << GREEN << this->_name << RESET << " starts their shift guarding the gate." << std::endl;
	}
	else
		std::cout << GREEN << this->_name << RESET << " ends their shift guarding the gate." << std::endl;
	this->_guard = !this->_guard;
}