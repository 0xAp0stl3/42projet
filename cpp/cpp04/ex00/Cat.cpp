/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:45 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:16:55 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->_type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cp) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cp;
}

Cat::~Cat(void)
{
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->getType() << " Meeeeeeeeeow" << std::endl;
}