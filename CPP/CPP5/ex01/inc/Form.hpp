#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class Form
{
	private:
			const str _name;
			bool _signed;
			const int _signGrade;
			const int _exeGrade;
	
	public:
			Form();
			Form(str name, const int sign, const int exe);
			Form(const Form& copy);
			Form& operator=(const Form& copy);
			~Form();

			str getName() const;
			bool getSigned() const;
			int getSignGrade() const;
			int getExeGrade() const;

			void beSigned(Bureaucrat& suit);

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