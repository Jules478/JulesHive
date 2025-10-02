#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <unistd.h>

Base* generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			std::cout << "Class " << BLUE << "A" << RESET << " generated" << std::endl;
			return new A;
		case 1:
			std::cout << "Class " << RED << "B" << RESET << " generated" << std::endl;
			return new B;
		case 2:
			std::cout << "Class " << GREEN << "C" << RESET << " generated" << std::endl;
			return new C;
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BLUE << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << RED << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << BLUE << "A" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << RED << "B" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "C" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}
}

int main()
{
	pid_t pid = getpid();
	srand(pid);
	Base* ptr = generate();
	Base& ref = *ptr;

	std::cout << "Pointer identification: ";
	identify(ptr);
	std::cout << "Reference identification: ";
	identify(ref);
	delete ptr;
	return 0;
}