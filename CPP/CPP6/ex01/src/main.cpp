#include "../inc/Serializer.hpp"

int main()
{
	Data* a = new Data;
	Data* b = new Data;

	a->name = "Andrew";
	a->age = 50;
	b->name = "Brenda";
	b->age = 33;

	std::cout << PURPLE << "/////" << RESET << " Before Serialization " << PURPLE << "/////" << RESET << std::endl;
	std::cout << a->name << ", " << a->age << std::endl;
	std::cout << b->name << ", " << b->age << std::endl;
	uintptr_t c = Serializer::serialize(a);
	uintptr_t d = Serializer::serialize(b);
	Data* e = Serializer::deserialize(c);
	Data* f = Serializer::deserialize(d);

	std::cout << std::endl << PURPLE << "/////" << RESET << " After Serialization " << PURPLE << "/////" << RESET << std::endl;
	std::cout << e->name << ", " << e->age << std::endl;
	std::cout << f->name << ", " << f->age << std::endl;

	delete a;
	delete b;

	return 0;
}