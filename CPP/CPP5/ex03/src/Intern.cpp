#include "../inc/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(str form, str target)
{
	int i = -1;
	str forms[] = { "PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm" };
	while (forms[++i] != form);
	switch (i)
	{
		case 0:
				std::cout << "Intern creates form " << PURPLE << form << RESET << std::endl;
				return new PresidentialPardonForm(target);
		case 1:
				std::cout << "Intern creates form " << PURPLE << form << RESET << std::endl;
				return new RobotomyRequestForm(target);
		case 2:
				std::cout << "Intern creates form " << PURPLE << form << RESET << std::endl;
				return new ShrubberyCreationForm(target);
		default:
				std::cout << "Form " << PURPLE << form << RESET << " does not exist" << std::endl;
	}
	return nullptr;
}
