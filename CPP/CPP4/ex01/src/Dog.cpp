#include "../inc/Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain;
	this->_type = "Dog";
	std::cout << RED << "Dog" << RESET << " was adopted from the shelter" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->_type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	std::cout << RED << "Dog" << RESET << " made a puppy just like it" << std::endl;
}

Dog &Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->_brain = new Brain(*copy._brain);
		this->_type = copy._type;
	}
	std::cout << RED << "Dog" << RESET <<  " became another dog (has science gone too far?)" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Dog" << RESET << " went to a farm" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << RED << "Woof!" << RESET << std::endl;
}