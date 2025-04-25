/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:38 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 10:49:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trevor("trevor");
	ClapTrap	franklin("franklin");
	ClapTrap	franklinclone = franklin;
	
	trevor.attack("franklin");
	franklin.takeDamage(5);
	trevor.beRepaired(3);
	franklin.attack("trevor");
	trevor.takeDamage(14);
	trevor.attack("Franklin");
	franklin.beRepaired(5);

	for (int i = 0; i < 11; i++) {
		franklinclone.attack("trevor");
	}
	
	return (0);
}