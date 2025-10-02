#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
	{
		// tests

		std::cout << PURPLE << "-----" << RESET << " Tests " << PURPLE << "-----" << RESET << std::endl;
		Bureaucrat harvey("Harvey", 1);
		Bureaucrat rachel("Rachel", 20);
		Bureaucrat mike("Mike", 60);
		Bureaucrat louis("Louis", 140);


		PresidentialPardonForm a("Arthur Dent");
		PresidentialPardonForm b("Ford Prefect");
		PresidentialPardonForm c("Tricia McMillan");
		PresidentialPardonForm d("Marvin");
		RobotomyRequestForm e("Arthur Dent");
		RobotomyRequestForm f("Ford Prefect");
		RobotomyRequestForm g("Tricia McMillan");
		RobotomyRequestForm h("Marvin");
		ShrubberyCreationForm i("Home");
		ShrubberyCreationForm j("Work");
		ShrubberyCreationForm k("Park");
		ShrubberyCreationForm l("School");



		std::cout << std::endl;

		std::cout << YELLOW << "---" << RESET << " Sign Forms " << YELLOW << "---" << RESET << std::endl;
		harvey.signForm(a);
		rachel.signForm(b);
		mike.signForm(c);
		louis.signForm(d);
		std::cout << std::endl;
		harvey.signForm(e);
		rachel.signForm(f);
		mike.signForm(g);
		louis.signForm(h);
		std::cout << std::endl;
		harvey.signForm(i);
		rachel.signForm(j);
		mike.signForm(k);
		louis.signForm(l);
		std::cout << std::endl;

		std::cout << YELLOW << "---" << RESET << " Execute Forms " << YELLOW << "---" << RESET << std::endl;
		harvey.executeForm(a);
		rachel.executeForm(b);
		mike.executeForm(c);
		louis.executeForm(d);
		std::cout << std::endl;
		harvey.executeForm(e);
		rachel.executeForm(f);
		mike.executeForm(g);
		louis.executeForm(h);
		std::cout << std::endl;
		harvey.executeForm(i);
		rachel.executeForm(j);
		mike.executeForm(k);
		louis.executeForm(l);
		std::cout << std::endl;

		std::cout << YELLOW << "---" << RESET << " Copied Forms " << YELLOW << "---" << RESET << std::endl;
		PresidentialPardonForm m(a);
		RobotomyRequestForm n;
		n = e;
		harvey.executeForm(m);
		rachel.executeForm(n);


	}
	return 0;
}