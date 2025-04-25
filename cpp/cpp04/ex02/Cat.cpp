/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:45 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:55:27 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cerr << "Brain allocation failed" << std::endl;
        exit(1);
    }
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cp) : AAnimal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cp;
}

Cat::~Cat(void)
{
    delete(this->_brain);
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat operator assignation called" << std::endl;
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