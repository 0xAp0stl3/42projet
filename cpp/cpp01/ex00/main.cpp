/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:33:33 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:37:47 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");
	Zombie	zombie3;
	
	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("ZombieRandomChump");
	
	std::cout << std::endl;

	Zombie	*heapZombie;

	heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete(heapZombie);
	
	return (0);
}