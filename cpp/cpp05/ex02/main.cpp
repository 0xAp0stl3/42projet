/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:48 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:41:59 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"   // erreurs
#define GREEN   "\033[32m"   // succès
#define YELLOW  "\033[33m"   // info
#define BLUE    "\033[34m"   // titres / séparateurs

int main() 
{
	std::cout << BLUE << "-----------TEST SHRUBBERY----------" << RESET << std::endl;
	try 
	{
		Bureaucrat alice("Alice", 130); // Grade 130
		ShrubberyCreationForm form("Garden");
		
		std::cout << YELLOW << alice.getName() << " is trying to sign the form..." << RESET << std::endl;
		alice.signForm(form);
		std::cout << YELLOW << alice.getName() << " is trying to execute the form..." << RESET << std::endl;
		alice.executeForm(form); // Alice exécute le formulaire
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	
	try 
	{
		Bureaucrat bob("Bob", 150); // Grade trop faible pour signer ou exécuter
		ShrubberyCreationForm form("Park");
		
		std::cout << YELLOW << bob.getName() << " is trying to sign the form..." << RESET << std::endl;
		bob.signForm(form); // Bob tente de signer
		std::cout << YELLOW << bob.getName() << " is trying to execute the form..." << RESET << std::endl;
		bob.executeForm(form);  // Bob tente d'exécuter
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "--------TEST FINISH SHRUBBERY-------" << RESET << std::endl;
	
	std::cout << BLUE << "------------TEST ROBOTOMY-----------" << RESET << std::endl;
	try 
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm form("Target1");
		
		std::cout << YELLOW << alice.getName() << " is trying to sign the form..." << RESET << std::endl;
		alice.signForm(form);
		std::cout << YELLOW << alice.getName() << " is trying to execute the form..." << RESET << std::endl;
		alice.executeForm(form);
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	
	try 
	{
		Bureaucrat bob("Bob", 80);
		RobotomyRequestForm form("Target2");
		
		std::cout << YELLOW << bob.getName() << " is trying to sign the form..." << RESET << std::endl;
		bob.signForm(form); // Bob peut signer
		std::cout << YELLOW << bob.getName() << " is trying to execute the form..." << RESET << std::endl;
		bob.executeForm(form); // Bob tente d'exécuter (peut échouer)
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "--------TEST FINISH ROBOTOMY-------" << RESET << std::endl;
	
	std::cout << BLUE << "----------TEST PRESIDENTIAL--------" << RESET << std::endl;
	try 
	{
		Bureaucrat alice("Alice", 5); // Grade 5 : suffisant pour exécuter
		PresidentialPardonForm form("Bob");
		
		std::cout << YELLOW << alice.getName() << " is trying to sign the form..." << RESET << std::endl;
		alice.signForm(form); // Alice signe le formulaire
		std::cout << YELLOW << alice.getName() << " is trying to execute the form..." << RESET << std::endl;
		alice.executeForm(form); // Alice exécute le formulaire
    }
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << RESET << std::endl;
	}
	
	try 
	{
		Bureaucrat bob("Bob", 30); // Grade insuffisant pour exécuter
		PresidentialPardonForm form("Charlie");
		
		std::cout << YELLOW << bob.getName() << " is trying to sign the form..." << RESET << std::endl;
		bob.signForm(form);  // Bob signe le formulaire
		std::cout << YELLOW << bob.getName() << " is trying to execute the form..." << RESET << std::endl;
		bob.executeForm(form);   // Lance une exception (grade insuffisant)
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "[ERROR]" << e.what() << std::endl;
	}
	std::cout << BLUE << "------TEST FINISH PRESIDENTIAL-----" << RESET << std::endl;

    return (0);
}