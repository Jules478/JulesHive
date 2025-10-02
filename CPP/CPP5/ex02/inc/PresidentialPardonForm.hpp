#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

typedef std::string str;

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
			str _target;
			void performAction() const;

	public:
			PresidentialPardonForm();
			PresidentialPardonForm(str target);
			PresidentialPardonForm(const PresidentialPardonForm& copy);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
			virtual ~PresidentialPardonForm();
			
};