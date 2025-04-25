/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:35:32 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:44:17 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	
	std::cout << "-------------------------MEMORY-------------------------" << std::endl;
	std::cout << "This is the memory address of brain: " << &brain << std::endl;
	std::cout << "This is the memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "This is the memory address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "-------------------------VALUE--------------------------" << std::endl;
	std::cout << "This is the value of brain: " << brain << std::endl;
	std::cout << "This is the value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "This is the value of stringREF: " << stringREF << std::endl;
}