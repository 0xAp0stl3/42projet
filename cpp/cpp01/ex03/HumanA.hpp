/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainA.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:13:25 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:45:59 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon	&_weapon;
		
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
		void	attack(void) const;	
};

#endif