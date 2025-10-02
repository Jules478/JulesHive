#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef std::string str;

class Intern
{
	public:
			Intern();
			Intern(const Intern& copy);
			Intern& operator=(const Intern& copy);
			~Intern();

			AForm* makeForm(str form, str target);
};