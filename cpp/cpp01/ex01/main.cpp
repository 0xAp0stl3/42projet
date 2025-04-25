/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:56:37 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:42:58 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	Zombie	*horde;
	int	N;
	std::string name = "Zombie";
	
	if (ac >= 2)
	{
		if (atoi(av[1]) <= 0)
		{
			std::cout << "The horde can't not be 0 or letters" << std::endl;
			return (0);
		}
		else if (atoi(av[1]) == 1)
		{
			N = 1;
			std::cout << "Bro this is not the horde cmon" << std::endl;
		}
		else if (atoi(av[1]) > 1 && atoi(av[1]) <= 2000)
			N = atoi(av[1]);
		else
			N = 5;
	}
	else
		N = 10;

	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete [] horde;
	std::cout << "Horde of " << N << " zombie is dead" << std::endl;
	return (0);
}