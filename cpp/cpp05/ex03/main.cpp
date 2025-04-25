/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:48 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:56:41 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() 
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

    // Création et exécution d'un formulaire valide
	AForm* form1 = intern.makeForm("ShrubberyCreationForm", "Garden");
	if (form1) 
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}

    // Tentative de création d'un formulaire invalide
	AForm* form2 = intern.makeForm("InvalidForm", "Nowhere");
	if (!form2) 
	{
		std::cout << "Failed to create form: InvalidForm." << std::endl;
	}

    // Création et exécution d'un formulaire de type RobotomyRequestForm
	AForm* form3 = intern.makeForm("RobotomyRequestForm", "Bender");
	if (form3) 
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}

	AForm* form4 = intern.makeForm("PresidentialPardonForm", "Alice");
	if (form4) 
	{
		boss.signForm(*form4);
		boss.executeForm(*form4);
		delete form4;
	}
	return (0);
}