#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	{
		// tests

		std::cout << PURPLE << "-----" << RESET << " Tests " << PURPLE << "-----" << RESET << std::endl;
		Intern roni;
		Bureaucrat harvey("Harvey", 1);
		Bureaucrat rachel("Rachel", 20);
		Bureaucrat mike("Mike", 60);
		Bureaucrat louis("Louis", 140);
		AForm* test;
		test = roni.makeForm("PresidentialPardonForm", "Jules");
		if (test)
		{
			harvey.signForm(*test);
			harvey.executeForm(*test);
			delete test;
		}
		test = roni.makeForm("RobotomyRequestForm", "Jules");
		if (test)
		{
			rachel.signForm(*test);
			rachel.executeForm(*test);
			delete test;
		}
		test = roni.makeForm("ShrubberyCreationForm", "Hive");
		if (test)
		{
			mike.signForm(*test);
			mike.executeForm(*test);
			delete test;
		}
		test = roni.makeForm("MilkshakeMakingForm", "Jules");
		if (test)
		{
			louis.signForm(*test);
			louis.executeForm(*test);
			delete test;
		}
	}
	return 0;
}