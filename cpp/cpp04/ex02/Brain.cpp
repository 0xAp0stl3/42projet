/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:07:39 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:22:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &cp)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = cp;
}

Brain::~Brain(void)
{
    std::cout << "Default Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain operator assignation called" << std::endl;
    if (this == &src)
        return (*this);

    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return (*this);
}

const std::string Brain::getIdeas(unsigned long index) const
{
    if (index < 100)
        return (this->_ideas[index]);
    else
        return ("Ideas out of range");
    
}

void    Brain::setIdeas(unsigned long index, std::string idea)
{
    if (index < 100)
        this->_ideas[index] = idea;
    else
        std::cout << "Index out of range in Brain::setIdeas" << std::endl;
}