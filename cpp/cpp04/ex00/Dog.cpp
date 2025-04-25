/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:21:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &cp) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
}

Dog::~Dog(void)
{
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->getType() << " Woof" << std::endl;
}