/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:57 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:39:27 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;
	std::cout << "ScavTrap default constructor called " <<  this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp)
{
	std::cout << "ScavTrap copy constructor called " << cp._name << std::endl;
	*this = cp;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;
	std::cout << "ScavTrap constructor set called " << this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assignation operator called " << src._name << std::endl;
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy_points = src._energy_points;
	this->_hit_points = src._hit_points;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " \
		<< this->_attack_damage << " points of degats." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)	
		std::cout << "ScavTrap " << this->_name << " is out of energy." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is out of hit points." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " has entered in Gate." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)	
		std::cout << "ScavTrap " << this->_name << " is out of energy." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is out of hit points." << std::endl;
}