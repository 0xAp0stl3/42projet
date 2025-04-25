/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:57 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 09:12:08 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class	Array
{
	private:
		unsigned int	_size;
		T				*_array;
	public:
		Array() : _size(0), _array(NULL)
		{
			std::cout << "Array constructor default called with size 0" << std::endl;
		}
		
		Array(unsigned int n) : _size(n), _array(n ? new T[n]() : NULL)
		{
			std::cout << "Array constructor called with size " << n << std::endl;
		}
		
		Array(const Array& cp) : _size(cp._size), _array(cp._size ? new T[cp._size] : NULL)
		{
			std::cout << "Array constructor copie called with size " << _size << std::endl;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = cp._array[i];
		}
		
		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			delete[] _array;
		}
		
		Array &operator=(const Array& src)
		{
			std::cout << "Array constructor assignation called" << std::endl;
			if (this != &src)
			{
				delete[] _array;
				_size = src._size;
				_array = _size ? new T[_size]: NULL;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}
		
		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw Array<T>::IndexException();
			return _array[index];
		}
		
		const T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw Array<T>::IndexException();
			return _array[index];
		}
		
		unsigned int size() const { return _size; }
		
		class IndexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
const char	*Array<T>::IndexException::what() const throw()
{
	return ("Erreur: index erreur");
}