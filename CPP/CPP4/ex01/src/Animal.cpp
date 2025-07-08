#include "../inc/Animal.hpp"

Animal::Animal() : _type("Animal_Default")
{
	std::cout << GREEN << "Animal base class" << RESET << " constructed" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	this->_type = copy._type;
	std::cout << GREEN << "Animal base class" << RESET << " copied from constructor" << std::endl;
}

Animal &Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << GREEN << "Animal base class" << RESET << " copied using assignment operator" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << GREEN << "Animal base class" << RESET << " deconstructed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << GREEN << "Default Animal" << RESET << " noise" << std::endl;
}

str Animal::getType() const
{
	return this->_type;
}