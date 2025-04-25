/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 01:15:28 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _brain(new Brain())
{
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &cp) : Animal(), _brain(new Brain(*cp._brain)) 
{
    this->_type = cp._type;
    std::cout << "Dog copy constructor called" << std::endl;
    
}

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->getType() << " Woof" << std::endl;
}

void    Dog::getIdeas(void) const
{
    for (int i = 0; i < 3; i++)
        std::cout << "Ideas: " << i << " of the dog is " << this->_brain->getIdeas(i) << std::endl;
}

void    Dog::setIdeas(unsigned long index, std::string idea)
{
    this->_brain->setIdeas(index, idea);
}