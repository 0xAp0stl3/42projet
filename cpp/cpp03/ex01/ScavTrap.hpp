/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:55 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:39:32 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& cp);
		ScavTrap(std::string name);
		virtual ~ScavTrap();
		
		ScavTrap &operator=(const ScavTrap &src);
		
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif