#include "../inc/Bureaucrat.hpp"

int main()
{
	{
		// Constructor tests

		std::cout << PURPLE << "-----" << RESET << " Constructor Tests " << PURPLE << "-----" << RESET << std::endl;
		Bureaucrat a;
		Bureaucrat b("Harvey", 1);
		Bureaucrat c(b);
		Bureaucrat d("Louis", 10);
		Bureaucrat e;
		e = d;

		std::cout << YELLOW << "Bureatcrat a:" << std::endl << a << std::endl;
		std::cout << YELLOW << "Bureatcrat b:" << std::endl << b << std::endl;
		std::cout << YELLOW << "Bureatcrat c:" << std::endl << c << std::endl;
		std::cout << YELLOW << "Bureatcrat d:" << std::endl << d << std::endl;
		std::cout << YELLOW << "Bureatcrat e:" << std::endl << e << std::endl;
		std::cout << std::endl;
	}
	{
		// Exception tests

		std::cout << PURPLE << "-----" << RESET << " Exception Tests " << PURPLE << "-----" << RESET << std::endl;
		try { Bureaucrat a("Harvey", 0); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { Bureaucrat b("Louis", 151); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { Bureaucrat c("Rachel", -1); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { Bureaucrat d("Donna", 10000); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		std::cout << std::endl;
	}
	{
		// Grade modifying tests

		std::cout << PURPLE << "-----" << RESET << " Grade Modifying Tests " << PURPLE << "-----" << RESET << std::endl;
		Bureaucrat a("Harvey", 1);
		Bureaucrat b("Louis", 150);
		std::cout << a << std::endl;
		a.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
		try { a.increaseGrade(); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { a.increaseGrade(); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { b.decreaseGrade(); }
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		try { b.decreaseGrade(); } 
		catch (const std::exception& e) { std::cout << e.what() << std::endl; }
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	return 0;
}