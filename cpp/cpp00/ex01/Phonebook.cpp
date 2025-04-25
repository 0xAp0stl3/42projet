/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:53 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 10:21:32 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_i = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Bye !" << std::endl;
}

Contact PhoneBook::get_contact(int i)
{
	return (this->_contact[i % 8]);
}

void	PhoneBook::add(void)
{
	std::string str;

	str = "";
	if (this->_i > 7)
		std::cout << "Becareful, the directory will delete the first contact." << std::endl;
	while ((!std::cin.eof() && str == "") || (str >= "0" && str <= "9"))
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[this->_i % 8].set_first_name(str);
	}
	str = "";
	while ((!std::cin.eof() && str == "") || (str >= "0" && str <= "9"))
	{
		std::cout << "Enter " << this->_contact[this->_i % 8].get_first_name() << " last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[this->_i % 8].set_last_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contact[this->_i % 8].get_first_name() << " nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[this->_i % 8].set_nickname(str);
	}
	str = "";
	while ((!std::cin.eof() && str == "") || (str >= "a" && str <= "z") || (str >= "A" && str <= "Z"))
	{
		std::cout << "Enter " << this->_contact[this->_i % 8].get_first_name() << " phone: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[this->_i % 8].set_phone_number(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contact[this->_i % 8].get_first_name() << " secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contact[this->_i % 8].set_secret(str);
			std::cout << "Sucessful " << this->_contact[this->_i % 8].get_first_name() << \
				" has been add !" << std::endl;
		}
	}
	this->_i++;
}

std::string	truncate(const std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return (str);
}

bool	PhoneBook::displayContactList(void) const
{
	bool is_empty = true;
	int i;
	for (i = 0; i < 8; i++)
	{
		if (!this->_contact[i].get_first_name().empty())
		{
			is_empty = false;
			break;
		}
	}
	if (is_empty)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return false;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
			  
	for (i = 0; i < 8; i++)
	{
		if (this->_contact[i].get_first_name().empty())
			continue;
		
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << truncate(this->_contact[i].get_first_name()) << "|"
				  << std::setw(10) << truncate(this->_contact[i].get_last_name()) << "|"
				  << std::setw(10) << truncate(this->_contact[i].get_nickname()) << std::endl;
	}
	return true;
}

void	PhoneBook::promptAndDisplayContact(void)
{
	std::string str;
	while (!std::cin.eof())
	{
		std::cout << "Select an index [0 for exit]: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8')
			{
				int index = str[0] - '1';
				if (!this->_contact[index].get_first_name().empty())
				{
					this->display(this->_contact[index]);
					break;
				}
			}
		}
		if (str == "0")
			break;
		std::cout << "Invalid index." << std::endl;
	}
}

void	PhoneBook::search(void)
{
	if (this->displayContactList())
		this->promptAndDisplayContact();
}

void	PhoneBook::display(Contact contact)
{
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Secret: " << contact.get_secret() << std::endl;
}