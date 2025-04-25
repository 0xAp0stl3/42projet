/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:55:43 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
    this->_type = "Dog";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cerr << "Brain allocation failed" << std::endl;
        exit(1);
    }
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &cp) : AAnimal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
}

Dog::~Dog(void)
{
    delete(this->_brain);
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    this->_type = src._type;
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cerr << "Brain allocation failed" << std::endl;
        exit(1);
    }
    *this->_brain = *src._brain;
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