/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:18 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 09:18:44 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int    main(void)
{
    PhoneBook    pb;
    std::string    str;
    
    while (true)
    {
        std::cout << "Enter a command [ADD, SEARCH or EXIT]: ";
        if (!std::getline(std::cin, str))
        {
            std::cout << std::endl;
            break;
        }
        if (str == "EXIT")
            break;
        else if (str == "ADD")
            pb.add();
        else if (str == "SEARCH")
            pb.search();
        else
            std::cout << "Please enter a valid command." << std::endl;
    }
    return (0);
}