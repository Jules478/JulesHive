#include "../inc/AForm.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false) , _signGrade(150), _exeGrade(150)
{
}

AForm::AForm(str name, int sign, int exe) : _name(name), _signed(false) , _signGrade(sign), _exeGrade(exe)
{
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exe < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed) , _signGrade(copy._signGrade), _exeGrade(copy._exeGrade)
{
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

str AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExeGrade() const
{
	return _exeGrade;
}

void AForm::setSigned(bool sign)
{
	_signed = sign;
}

void AForm::beSigned(Bureaucrat const &suit)
{
	if (_signGrade < suit.getGrade())
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const &suit)
{
	if (_signed == false)
		throw FormNotSignedException();
	else if (suit.getGrade() > _exeGrade)
		throw GradeTooLowException();
	else
		performAction();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form not signed";
}