#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	{
		std::cout << PURPLE << "/////" << RESET << " Subject Tests " << PURPLE << "/////" << RESET << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << std::endl << PURPLE << "/////" << RESET << " Own Tests " << PURPLE << "/////" << RESET << std::endl;
		
		// Create some animals
		Dog a = Dog();
		Cat b = Cat();
		std::cout << std::endl;

		// Speak
		a.makeSound();
		b.makeSound();
		std::cout << std::endl;

		// Copy the animals
		Dog c = Dog(a);
		Cat d = Cat(b);
		std::cout << std::endl;

		// Copy the animals with assignment operator
		Dog e = a;
		Cat f = b;
		std::cout << std::endl;

		// Show that animals are deep copies
		std::cout << "Original Dog and Copy Dog are " << (&a == &c ? "same" : "different") << " objects" << std::endl;
		std::cout << "Original Cat and Copy Cat are " << (&b == &d ? "same" : "different") << " objects" << std::endl;
		std::cout << std::endl;

		// Tests to show Animal class is Abstract
		// Animal g;
		// Animal h(g);
		// g.makeSound();
		// h.makeSound();
	}
	return 0;
}