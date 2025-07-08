#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() : _type("Default Materia")
{
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
}

MateriaSource::MateriaSource(str const &type) : _type(type)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	_type = copy._type;
	for (int i = 0; i < 4; i++)
		_inv[i] = copy._inv[i] ? copy._inv[i]->clone() : nullptr;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		for (int i = 0; i < 4; i++)
			_inv[i] = copy._inv[i] ? copy._inv[i]->clone() : nullptr;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_inv[i])
			delete _inv[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(str const & type)
{
	for (int i = 0; i < 4; i++)
		if (_inv[i] && _inv[i]->getType() == type)
			return this->_inv[i]->clone();
	return 0;
}