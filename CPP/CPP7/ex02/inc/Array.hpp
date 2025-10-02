#pragma once

#include <iostream>

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

template <typename T>
class Array
{
	private:
			T* _array;
			unsigned int _n;

	public:
			Array() : _n(0)
			{
				try { _array = new T[0]; }
				catch (...)
				{
					throw "Allocation Error!";
				}
			}

			Array(unsigned int n) : _n(n)
			{
				try { _array = new T[n]; }
				catch (...)
				{
					throw "Allocation Error!";
				}
			}

			Array(const Array& copy) : _n(copy._n)
			{
				try { _array = new T[copy._n]; }
				catch (...)
				{
					throw "Allocation Error!";
				}
				for (unsigned int i = 0; i < copy._n; i++)
					this->_array[i] = copy._array[i];
			}

			Array& operator=(const Array& copy)
			{
				if (this != &copy)
				{
					if (this->_array != nullptr)
						delete[] this->_array;
					try { this->_array = new T[copy._n]; }
					catch (...)
					{
						throw "Allocation Error!";
					}
					for (unsigned int i = 0; i < copy._n; i++)
						this->_array[i] = copy._array[i];
					this->_n = copy._n;
				}
				return (*this);
			}

			~Array()
			{
				delete[] _array;
			}
			
			T& operator[](unsigned int index)
			{
				if (index >= _n || _array == nullptr)
					throw InvalidIndexException();
				return this->_array[index];
			}

			const T& operator[](unsigned int index) const
			{
				if (index >= _n || _array == nullptr)
					throw InvalidIndexException();
				return this->_array[index];
			}

			class	InvalidIndexException : public std::exception
			{
				public:
						virtual const char	*what() const throw();
			};

			unsigned int getSize()
			{
				return _n;
			}
};

template <typename T>
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Invalid index");
}
