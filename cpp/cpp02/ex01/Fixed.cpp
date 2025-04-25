/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:36:18 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 08:40:58 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits_value = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::Fixed(const int conv)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = conv << this->_fract_bits_value;
}

Fixed::Fixed(const float conv)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(conv * (1 << this->_fract_bits_value));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fract_bits_value));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fract_bits_value);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}