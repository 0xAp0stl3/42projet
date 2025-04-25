/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:19 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:22:33 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("God")
{
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = cp;
}

Animal::~Animal(void)
{
    std::cout << "Default destructor Animal called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Animal operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void    Animal::makeSound(void) const
{
    std::cout << this->_type << " make a sound" << std::endl;
}

