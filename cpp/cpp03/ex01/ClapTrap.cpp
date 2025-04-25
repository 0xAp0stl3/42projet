/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:36 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:39:09 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("micheal"), _attack_damage(0), _energy_points(10), _hit_points(10)
{
	std::cout << "ClapTrap default constructor called " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp)
{
	std::cout << "ClapTrap copy constructor called " << cp._name << std::endl;
	*this = cp;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _attack_damage(0), _energy_points(10), _hit_points(10)
{
	std::cout << "ClapTrap constructor set called " << this->_name <<  std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap assignation operator called " << src._name << std::endl;
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy_points = src._energy_points;
	this->_hit_points = src._hit_points;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
		<< this->_attack_damage << " points of degats." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)	
		std::cout << "ClapTrap " << this->_name << " is out of energy." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is out of hit points." << std::endl;
		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage." << std::endl;
	this->_hit_points -= amount;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is repaired, gaining " \
		<< amount << "hit points back." << std::endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired." << std::endl;
}