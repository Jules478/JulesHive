#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->_dmg = 30;
	std::cout << RED << this->_name << RESET << " was built from a homemade kit." << std::endl;
}

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_dmg = 30;

	std::cout << RED << this->_name << RESET << " was built from a homemade kit." << std::endl;
}

FragTrap::FragTrap(const FragTrap& guy) : ClapTrap(guy)
{
	this->_name = guy._name;
	this->_hp = guy._hp;
	this->_ep = guy._ep;
	this->_dmg = guy._dmg;
	std::cout << RED << this->_name << RESET << " used the instructions of another FragTrap." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& guy)
{
	if (this != &guy)
	{
		this->_name = guy._name;
		this->_hp = guy._hp;
		this->_ep = guy._ep;
		this->_dmg = guy._dmg;
	}
	std::cout << RED << this->_name << RESET << " became another FragTrap." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << RED << this->_name << RESET << " was disassembled." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hp == 0)
		std::cout << RED << this->_name << RESET << " is too dead to give out high fives." << std::endl;
	else if (this->_ep == 0)
		std::cout << RED << this->_name << RESET << " is too tired to give out high fives." << std::endl;
	else
		std::cout << RED << this->_name << RESET << " gave you a really cool high five." << std::endl;
}