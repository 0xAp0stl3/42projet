/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:36:18 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 08:41:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits_value = 8;

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &cp)
{
	*this = cp;
}

Fixed::Fixed(const int conv)
{
	this->_value = conv << this->_fract_bits_value;
}

Fixed::Fixed(const float conv)
{
	this->_value = roundf(conv * (1 << this->_fract_bits_value));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	
	return *this;
}

bool Fixed::operator>(Fixed v) const
{
	return (this->toFloat() > v.toFloat());
}

bool Fixed::operator<(Fixed v) const
{
	return (this->toFloat() < v.toFloat());
}

bool Fixed::operator>=(Fixed v) const
{
	return (this->toFloat() >= v.toFloat());
}

bool Fixed::operator<=(Fixed v) const
{
	return (this->toFloat() <= v.toFloat());
}

bool Fixed::operator==(Fixed v) const
{
	return (this->toFloat() == v.toFloat());
}

bool Fixed::operator!=(Fixed v) const
{
	return (this->toFloat() != v.toFloat());
}

float Fixed::operator+(Fixed v) const
{
	return (this->toFloat() + v.toFloat());
}

float Fixed::operator-(Fixed v) const
{
	return (this->toFloat() - v.toFloat());
}

float Fixed::operator*(Fixed v) const
{
	return (this->toFloat() * v.toFloat());
}

float Fixed::operator/(Fixed v) const
{
	return (this->toFloat() / v.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed	&Fixed::min(Fixed &first, Fixed &sec)
{
	if (first.toFloat() <= sec.toFloat())
		return (sec);
	else
		return (first);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &sec)
{
	if (first.toFloat() <= sec.toFloat())
		return (first);
	else
		return (first);
}

Fixed	&Fixed::max(Fixed &first, Fixed &sec)
{
	if (first.toFloat() >= sec.toFloat())
		return (first);
	else
		return (sec);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &sec)
{
	if (first.toFloat() >= sec.toFloat())
		return (first);
	else
		return (sec);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}