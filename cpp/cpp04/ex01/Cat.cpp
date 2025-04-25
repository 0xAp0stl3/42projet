/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:45 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 01:15:21 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain())
{
    this->_type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cp) : Animal(), _brain(new Brain(*cp._brain))
{
    this->_type = cp._type;
    std::cout << "Cat copy constructor called" << std::endl;
    
}

Cat::~Cat(void)
{
    delete this->_brain;
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->getType() << " Meeeeeeeeeow" << std::endl;
}

void    Cat::getIdeas(void) const
{
    for (int i = 0; i < 3; i++)
        std::cout << "Ideas: " << i << " of the cat is " << this->_brain->getIdeas(i) << std::endl;
}

void    Cat::setIdeas(unsigned long index, std::string idea)
{
    this->_brain->setIdeas(index, idea);
}