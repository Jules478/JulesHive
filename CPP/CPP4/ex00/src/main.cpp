#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << PURPLE << "/////" << RESET << " Subject Tests " << PURPLE << "/////" << RESET << std::endl;
		// Construct the animals
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		// Display the animal types (dog or cat)
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		// Make the sound of the corrosponding animal type
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		// Cleanup
		delete i;	
		delete j;
		delete meta;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << PURPLE << "/////" << RESET << " Own Tests " << PURPLE << "/////" << RESET << std::endl;
		// Construct the animals
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;

		// Display the animal types (dog and WrongCat)
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		// Make the sound of the animal type (WrongCat will call WrongAnimal::makeSound)
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		// Cleanup
		delete i;	
		delete j;
		delete meta;
	}
	return 0;
}