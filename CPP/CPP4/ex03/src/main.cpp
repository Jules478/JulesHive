#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

int main()
{
	{
		std::cout << PURPLE << "/////" << RESET << " Subject Tests " << PURPLE << "/////" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}
	{
		std::cout << PURPLE << "/////" << RESET << " Own Tests " << PURPLE << "/////" << RESET << std::endl;
		
		// Create a new guy and teach him some magic
		ICharacter* guy = new Character("guy");
		IMateriaSource* book = new MateriaSource();
		book->learnMateria(new Ice());
		book->learnMateria(new Cure());
		AMateria* spell;
		spell = book->createMateria("ice");
		guy->equip(spell);
		spell = book->createMateria("cure");
		guy->equip(spell);

		// Create a guy to do the magic on
		ICharacter* buddy = new Character("buddy");
		guy->use(0, *buddy);
		guy->use(1, *buddy);
		std::cout << std::endl;

		// Delete book and see if the magic still works
		delete book;
		guy->use(0, *buddy);
		guy->use(1, *buddy);
		std::cout << std::endl;

		// Make copy of guy
		Character* guy_char = dynamic_cast<Character*>(guy);
		Character* dude = new Character(*guy_char);
		delete guy;
		dude->use(0, *buddy);
		dude->use(1, *buddy);

		delete dude;
		delete buddy;
		std::cout << std::endl;
	}
	{
		// Fill up spell slots on book
		ICharacter* guy = new Character("guy");
		ICharacter* buddy = new Character("buddy");
		IMateriaSource* book = new MateriaSource();
		book->learnMateria(new Ice());
		book->learnMateria(new Ice());
		book->learnMateria(new Ice());
		book->learnMateria(new Ice());
		AMateria* temp = new Cure();
		book->learnMateria(temp);
		AMateria* spell;
		spell = book->createMateria("ice");
		guy->equip(spell);
		spell = nullptr;
		guy->use(0, *buddy);
		spell = book->createMateria("cure");
		guy->equip(spell);
		guy->use(1, *buddy);
		delete temp;
		std::cout << std::endl;

		// Fill up the slots on guy
		spell = book->createMateria("ice");
		guy->equip(spell);
		spell = book->createMateria("ice");
		guy->equip(spell);
		spell = book->createMateria("ice");
		guy->equip(spell);
		guy->use(1, *buddy);
		guy->use(2, *buddy);
		guy->use(3, *buddy);
		IMateriaSource* newbook = new MateriaSource();
		newbook->learnMateria(new Cure());
		spell = newbook->createMateria("cure");
		guy->equip(spell);
		guy->use(0, *buddy);
		guy->use(1, *buddy);
		guy->use(2, *buddy);
		guy->use(3, *buddy);
		buddy->equip(spell);
		buddy->use(0, *guy);
		
		delete buddy;
		delete guy;
		delete book;
		delete newbook;
	}
	return 0;
}