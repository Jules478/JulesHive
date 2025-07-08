#include "../inc/Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain;
	this->_type = "Cat";
	std::cout << BLUE << "Cat" << RESET << " was adopted from the streets" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->_type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	std::cout << BLUE << "Cat" << RESET << " made a kitten just like it" << std::endl;
}

Cat &Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	std::cout << BLUE << "Cat" << RESET << " became another Cat (has science gone too far?)" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << BLUE << "Cat" << RESET << " ran away" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << BLUE << "Meow!" << RESET << std::endl;
}