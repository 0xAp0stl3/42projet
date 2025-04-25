/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:27 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 01:25:24 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

int main()
{
	std::cout << "\n--- Test de Base : Création et Suppression d'Animaux ---" << std::endl;

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << " sound : ";
	dog->makeSound();

	std::cout << cat->getType() << " sound : ";
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n--- Test de Copie et d'Affectation ---" << std::endl;

	Dog originalDog;
	Dog copyDog(originalDog);
	Dog assignedDog = originalDog;

	Cat originalCat;
	Cat copyCat(originalCat);
	Cat assignedCat = originalCat;

	std::cout << "Original Dog: " << originalDog.getType() << " - ";
	originalDog.makeSound();

	std::cout << "Copied Dog: " << copyDog.getType() << " - ";
	copyDog.makeSound();

	std::cout << "Assigned Dog: " << assignedDog.getType() << " - ";
	assignedDog.makeSound();

	std::cout << "Original Cat: " << originalCat.getType() << " - ";
	originalCat.makeSound();

	std::cout << "Copied Cat: " << copyCat.getType() << " - ";
	copyCat.makeSound();

	std::cout << "Assigned Cat: " << assignedCat.getType() << " - ";
	assignedCat.makeSound();

	return 0;
}