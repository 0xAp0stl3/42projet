/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:37:01 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 11:35:39 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	// Vérification du nombre d'arguments
	if (argc != 2) 
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1); // Code d'erreur
	}
	
	// Récupération du littéral
	std::string literal = argv[1];
	
	// Appel de la méthode convert
	try 
	{
		ScalarConverter::convert(literal);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1); // Code d'erreur
	}
	return (0); // Succès
}