/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:28:12 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:46:41 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon	*_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif