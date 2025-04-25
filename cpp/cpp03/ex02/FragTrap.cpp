/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:55:26 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:40:45 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_attack_damage = 30;
	this->_energy_points = 100;
	this->_hit_points = 100;
	std::cout << "FragTrap default constructor called " <<  this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp)
{
	std::cout << "FragTrap copy constructor called " << cp._name << std::endl;
	*this = cp;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_attack_damage = 30;
	this->_energy_points = 100;
	this->_hit_points = 100;
	std::cout << "FragTrap constructor set called " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap assignation operator called " << src._name << std::endl;
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy_points = src._energy_points;
	this->_hit_points = src._hit_points;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "FragTrap " << this->_name << " high five bro." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)	
		std::cout << "FragTrap " << this->_name << " is out of energy." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is out of hit points." << std::endl;
}