#include "../inc/Form.hpp"

Form::Form() : _name("Default Form"), _signed(false) , _signGrade(150), _exeGrade(150)
{
}

Form::Form(str name, int sign, int exe) : _name(name), _signed(false) , _signGrade(sign), _exeGrade(exe)
{
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exe < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed) , _signGrade(copy._signGrade), _exeGrade(copy._exeGrade)
{
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

Form::~Form()
{
}

str Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExeGrade() const
{
	return _exeGrade;
}

void Form::beSigned(Bureaucrat& suit)
{
	if (_signGrade < suit.getGrade())
		throw GradeTooLowException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}