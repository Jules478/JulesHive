#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal_Default")
{
	std::cout << GREEN << "WrongAnimal base class" << RESET << " constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << GREEN << "WrongAnimal base class" << RESET << " copied from constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << GREEN << "WrongAnimal base class" << RESET << " copied using assignment operator" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal base class" << RESET << " deconstructed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "Default WrongAnimal" << RESET << " noise" << std::endl;
}

str WrongAnimal::getType() const
{
	return this->_type;
}