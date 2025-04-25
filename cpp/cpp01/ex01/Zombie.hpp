/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:42:28 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:43:16 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);
		Zombie(std::string name);
		
		void	set_name(std::string name);
		void	announce(void) const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif