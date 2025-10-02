#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>

typedef std::string str;

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
			str _target;
			void performAction() const;

	public:
			RobotomyRequestForm();
			RobotomyRequestForm(str target);
			RobotomyRequestForm(const RobotomyRequestForm& copy);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
			virtual ~RobotomyRequestForm();
			
};