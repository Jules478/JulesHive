#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Random Suit"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const str name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

str Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
	
}

void Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &suit)
{
	o << BLUE << suit.getName() << RESET << ", bureaucrat grade " << PURPLE << suit.getGrade() << RESET;
	return o;
}

void Bureaucrat::signForm(AForm &form)
{
	try { form.beSigned(*this); }
	catch (const std::exception& e) { std::cout << BLUE << _name << RESET << " couldn't sign " << PURPLE << form.getName() << RESET << " because " << e.what() << std::endl; return; }
	std::cout << BLUE << _name << RESET << " signed " << PURPLE << form.getName() << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm &form)
{
	try { form.execute(*this); }
	catch (const std::exception& e) { std::cout << BLUE << _name << RESET << " cannot execute " << PURPLE << form.getName() << RESET << " because " << e.what() << std::endl; return; }
	std::cout << BLUE << _name << RESET << " executed " << PURPLE << form.getName() << RESET << std::endl;
}