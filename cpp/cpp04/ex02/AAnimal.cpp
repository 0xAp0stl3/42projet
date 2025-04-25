/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:49:50 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:54:52 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AGod")
{
    std::cout << "Default constructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cp)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = cp;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Default destructor AAnimal called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    std::cout << "AAnimal operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}