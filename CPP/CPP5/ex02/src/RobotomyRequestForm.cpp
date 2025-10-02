#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 75, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(str target) : AForm("Robotomy Request", 75, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		this->setSigned(copy.getSigned());
		this->_target = copy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::performAction() const
{
	std::srand(std::time(nullptr));
	if (std::rand() % 2 == 0)
		std::cout << RED << _target << RESET << " has been successfully robotomized" << std::endl;
	else
		std::cout << RED << _target << RESET << " has not been robotomized" << std::endl;
}
