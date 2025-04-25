/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:38 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:40:57 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	ClapTrap trevor("trevor");
	FragTrap franklin("franklin");
	FragTrap micheal;
	FragTrap franklinclone = franklin;

	trevor.attack("franklin");
	franklin.attack("trevor");
	franklin.takeDamage(2);
	franklin.beRepaired(1);
	franklin.highFiveGuys();

	franklin.takeDamage(100);
	franklin.attack("trevor");
	franklin.takeDamage(2);
	franklin.beRepaired(2);
	franklin.highFiveGuys();

	for (int i = 0; i < 101; i++) {
		franklinclone.attack("trevor");
	}

	return (0);
}