#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << CYAN << "Brain" << RESET << " constructed" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << CYAN << "Brain" << RESET << " copy constructed" << std::endl;
}

Brain &Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << CYAN << "Brain" << RESET << " deconstructed" << std::endl;
}
