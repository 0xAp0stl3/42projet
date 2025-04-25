/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:35 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:39:14 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int	_attack_damage;
		int	_energy_points;
		int	_hit_points;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& cp);
		ClapTrap(std::string _name);
		~ClapTrap();
		
		ClapTrap& operator=(const ClapTrap& src);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif