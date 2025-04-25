/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:38 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:39:20 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
	ClapTrap trevor("trevor");
	ScavTrap franklin("franklin");
	ScavTrap micheal;
	ScavTrap franklinclone = franklin;

	trevor.attack("franklin");
	franklin.attack("trevor");
	franklin.takeDamage(2);
	franklin.beRepaired(1);
	franklin.guardGate();

	franklin.takeDamage(100);
	franklin.attack("trevor");
	franklin.takeDamage(2);
	franklin.beRepaired(2);
	franklin.guardGate();

	for (int i = 0; i < 51; i++) {
		franklinclone.attack("trevor");
	}

	return (0);
}