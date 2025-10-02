#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

class AForm;

class Bureaucrat : public std::exception
{
	private:
			str _name;
			int	_grade;

	public:
			Bureaucrat();
			Bureaucrat(const str name, int grade);
			Bureaucrat(const Bureaucrat& copy);
			Bureaucrat& operator=(const Bureaucrat& copy);
			~Bureaucrat();

			str getName() const;
			int getGrade() const;

			void increaseGrade();
			void decreaseGrade();
			
			void signForm(AForm &form);

			void executeForm(AForm &form);
			
			class GradeTooHighException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &suit);