/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:16:59 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:45:42 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
}