#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default ClapTrap_clap_name")
{
	this->_name = "Default ClapTrap";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
	std::cout << BLUE << this->_name << RESET << " rolled out of the factory." << std::endl;
}

DiamondTrap::DiamondTrap(str name) : ClapTrap(name + "_clap_name"), _name(name)
{
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
	std::cout << BLUE << this->_name << RESET << " rolled out of the factory." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &guy) : ClapTrap(guy)
{
	this->_name = guy._name;
	this->_hp = guy._hp;
	this->_ep = guy._ep;
	this->_dmg = guy._dmg;
	std::cout << BLUE << this->_name << RESET << " copied another DiamondTrap." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &guy)
{
	if (this != &guy)
	{
		this->_name = guy._name;
		ClapTrap::_name = guy._name + "_clap_name";
		this->_hp = guy._hp;
		this->_ep = guy._ep;
		this->_dmg = guy._dmg;
	}
	std::cout << BLUE << this->_name << RESET << " equals another DiamondTrap." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << this->_name << RESET << " went to the scrapyard." << std::endl;
}

void DiamondTrap::attack(const str& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello! My name is " << BLUE << this->_name << RESET << " and my ClapTrap name is " << YELLOW << ClapTrap::_name << RESET << "." << std::endl;
}