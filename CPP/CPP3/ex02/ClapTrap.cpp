#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default ClapTrap"), _hp(10), _ep(10), _dmg(0)
{
	std::cout << YELLOW << "Default ClapTrap" << RESET " rolled out of the factory" << std::endl;
}

ClapTrap::ClapTrap(str name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << YELLOW << this->_name << RESET << " rolled out of the factory" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& guy)
{
	this->_name = guy._name;
	this->_hp = guy._hp;
	this->_ep = guy._ep;
	this->_dmg = guy._dmg;
	std::cout << YELLOW << this->_name << RESET << " copied another ClapTrap." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& guy)
{
	if (this != &guy)
	{
		this->_name = guy._name;
		this->_hp = guy._hp;
		this->_ep = guy._ep;
		this->_dmg = guy._dmg;
	}
	std::cout << YELLOW << this->_name << RESET << " equals another ClapTrap." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << this->_name << RESET << " went to the scrapyard." << std::endl;
}

void ClapTrap::attack(const str& target)
{
	if (this->_hp == 0)
		std::cout << YELLOW << this->_name << RESET << " cannot attack because it is dead." << std::endl;
	else if (this->_ep > 0)
	{
		this->_ep--;
		std::cout << YELLOW << this->_name << RESET << " attacks " << target << ", causing " << this->_dmg << " points of damage!" << std::endl;
	}
	else
		std::cout << YELLOW << this->_name << RESET << " has no energy to attack right now." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
		std::cout << YELLOW << this->_name << RESET << " is already dead." << std::endl;
	else
	{
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
		std::cout << "Bzzzt! " << YELLOW << this->_name << RESET << " took " << amount << " points of damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 0)
		std::cout << YELLOW << this->_name << RESET << " cannot repair because it is dead." << std::endl;
	else if (this->_ep > 0)
	{
		this->_ep--;
		if (this->_hp + amount > 1000 || amount > 1000)
			this->_hp = 1000;
		else
			this->_hp += amount;
		std::cout << YELLOW << this->_name << RESET << " was repaired for " << amount << " hit points." << std::endl;
	}
	else
		std::cout << YELLOW << this->_name << RESET << " has no energy to repair right now." << std::endl;
}