#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

typedef std::string str;

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
			str _target;
			void performAction() const;

	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(str target);
			ShrubberyCreationForm(const ShrubberyCreationForm& copy);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
			virtual ~ShrubberyCreationForm();
			
};