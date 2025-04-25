/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:02:25 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:40:09 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Zombie")
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}