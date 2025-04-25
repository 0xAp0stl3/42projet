/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:32:27 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:47:06 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}