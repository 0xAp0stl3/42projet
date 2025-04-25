/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:27 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 23:04:58 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{

    std::cout << "TEST ANIMAL" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Constructor:" << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
    
	std::cout << "Test:" << std::endl;
	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Destructor:" << std::endl;
	delete meta;
	std::cout << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;


    std::cout << "TEST ANIMAL CAT" << std::endl;
    std::cout << std::endl;
    
	std::cout << "Constructor:" << std::endl;
	const Animal	*danette = new Cat();
	std::cout << std::endl;

	std::cout << "Test:" << std::endl;
	std::cout << "Cat type: " << danette->getType() << std::endl;
	danette->makeSound();
	std::cout << std::endl;

	std::cout << "Destructor:" << std::endl;
	delete danette;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "TEST ANIMAL DOG" << std::endl;
    std::cout << std::endl;
    
	std::cout << "Constructor:" << std::endl;
	const Animal	*shana = new Dog();
	std::cout << std::endl;
    
	std::cout << "Test:" << std::endl;
	std::cout << "Dog type: " << shana->getType() <<std::endl;
	shana->makeSound();
	std::cout << std::endl;
    
	std::cout << "Destructor:" << std::endl;
	delete shana;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "TEST WRONGANIMAL" << std::endl;
    std::cout << std::endl;
    
	std::cout << "Constructor:" << std::endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "Test:" << std::endl;
	std::cout << "Animal type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << "Destructor:" << std::endl;
	delete wrong_meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

    std::cout << "TEST WRONGCAT" << std::endl;
    std::cout << std::endl;
    
	std::cout << "Constructor:" << std::endl;
	const WrongAnimal	*wrong_danette = new WrongCat();
	std::cout << std::endl;

	std::cout << "Test:" << std::endl;
	std::cout << "WrongCat type: " << wrong_danette->getType() <<std::endl;
	wrong_danette->makeSound();
	std::cout << std::endl;

	std::cout << "Destructor:" << std::endl;
	delete wrong_danette;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "TEST WRONGCAT" << std::endl;
    std::cout << std::endl;
    
	std::cout << "Constructor:" << std::endl;
	const WrongCat	*wrong_danetta = new WrongCat();
	std::cout << std::endl;

	std::cout << "Test:" << std::endl;
	std::cout << "WrongCat type: " << wrong_danetta->getType() <<std::endl;
	wrong_danetta->makeSound();
	std::cout << std::endl;

	std::cout << "Destructor:" << std::endl;
	delete wrong_danetta;
	std::cout << std::endl;

    std::cout << "TEST FINISH" << std::endl;
	return (0);
}