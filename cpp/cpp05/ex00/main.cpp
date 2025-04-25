/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:48 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:13:21 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      // erreurs
#define GREEN   "\033[32m"      // succès
#define YELLOW  "\033[33m"      // info

int main() 
{
	try 
	{
		Bureaucrat alice("Alice", 10);
		std::cout << GREEN << alice << RESET <<  std::endl;
		
		alice.increment();
		std::cout << YELLOW << "After increment: " << alice << RESET << std::endl;

		std::cout << GREEN << "Incrementing 10 times..." << RESET << std::endl;
		for (int i = 0; i < 10; ++i)
			alice.increment();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << "[ALICE] Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << std::string(40, '=') << std::endl;
	
	try
	{
		Bureaucrat bob("Bob", 140);
		std::cout << GREEN << bob << RESET << std::endl;
		
		bob.decrement();
		std::cout << YELLOW << "After decrement: " << bob << RESET << std::endl;
		
		std::cout << GREEN << "Decrementing 10 times..." << RESET << std::endl;
		for (int i = 0; i < 10; ++i)
			bob.decrement();
	}
	catch (const Bureaucrat::GradeTooLowException& e) 
	{
		std::cerr << RED << "[BOB] Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << std::string(40, '=') << std::endl;
	
	try 
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e) 
	{
		std::cerr << RED << "[INVALID] Exception caught: " << e.what() << RESET << std::endl;
    }
	
	try 
	{
		Bureaucrat invalid2("Invalid2", 151);
    }
	catch (const Bureaucrat::GradeTooLowException& e) 
	{
		std::cerr << RED << "[INVALID2] Exception caught: " << e.what() << RESET << std::endl;
	}
	return (0);
}