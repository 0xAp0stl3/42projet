/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:48 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:28:40 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"   // erreurs
#define GREEN   "\033[32m"   // succès
#define YELLOW  "\033[33m"   // info
#define BLUE    "\033[34m"   // titres / séparateurs

int main()
{
	try 
	{
		std::cout << BLUE << "=== Alice signe Report ===" << RESET << std::endl;
		Bureaucrat alice("Alice", 50); // Bureaucrate avec grade 50
		Form report("Report", 75, 50); // Formulaire avec grade requis pour signer 75
		
		std::cout << YELLOW << report << RESET << std::endl;
		
		alice.signForm(report); // Alice tente de signer
	
		std::cout << YELLOW << report << RESET << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	
	std::cout << std::string(40, '=') << std::endl;
	
	try 
	{
		std::cout << BLUE << "=== Bob signe Contract ===" << RESET << std::endl;
		Bureaucrat bob("Bob", 100); // Bureaucrate avec grade 100
		Form contract("Contract", 75, 50); // Formulaire avec grade requis pour signer 75
		
		std::cout << YELLOW << contract << RESET << std::endl;
		
		bob.signForm(contract); // Bob tente de signer, mais échoue
		
		std::cout << YELLOW << contract << RESET << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	
	std::cout << std::string(40, '=') << std::endl;
	return (0);
}

