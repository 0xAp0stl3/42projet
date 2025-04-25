/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:47 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 08:39:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

std::string        Contact::get_first_name(void) const
{
    return (this->_first_name);
}

std::string        Contact::get_last_name(void) const
{
    return (this->_last_name);
}

std::string        Contact::get_nickname(void) const
{
    return (this->_nickname);
}

std::string        Contact::get_phone_number(void) const
{
    return (this->_phone_number);
}

std::string        Contact::get_secret(void) const
{
    return (this->_secret);
}

void    Contact::set_first_name(std::string str)
{
    this->_first_name = str;
}

void    Contact::set_last_name(std::string str)
{
    this->_last_name = str;
}

void    Contact::set_nickname(std::string str)
{
    this->_nickname = str;
}

void    Contact::set_phone_number(std::string str)
{
    this->_phone_number = str;
}

void    Contact::set_secret(std::string str)
{
    this->_secret = str;
}