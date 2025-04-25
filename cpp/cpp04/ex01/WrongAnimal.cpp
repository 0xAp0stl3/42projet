/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:28:34 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:37:10 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("GodWrong")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = cp;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << this->getType() << " make a wrong sound" << std::endl;
}