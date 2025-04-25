/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:38:27 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:51:30 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = cp;
}

WrongCat::~WrongCat(void)
{
    std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << this->getType() << " wrong Meeeeeeeeeow" << std::endl;
}