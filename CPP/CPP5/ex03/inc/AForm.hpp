#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class AForm
{
	private:
			const str _name;
			bool _signed;
			const int _signGrade;
			const int _exeGrade;
			virtual void performAction() const = 0;
	
	public:
			AForm();
			AForm(str name, const int sign, const int exe);
			AForm(const AForm& copy);
			AForm& operator=(const AForm& copy);
			virtual ~AForm();

			str getName() const;
			bool getSigned() const;
			int getSignGrade() const;
			int getExeGrade() const;

			void setSigned(bool sign);

			void beSigned(Bureaucrat const &suit);

			void execute(Bureaucrat const &suit);

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

			class FormNotSignedException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};