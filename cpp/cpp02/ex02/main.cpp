/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:32:55 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 09:32:21 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() 
{
    // Tests de constructeurs
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    // Affichage des valeurs initiales
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    // Test d'assignation
    a = Fixed(1234.5678f);
    std::cout << "a après assignation = " << a << std::endl;

    // Test des opérateurs de comparaison
    std::cout << std::boolalpha;
    std::cout << "b < c ? " << (b < c) << std::endl;
    std::cout << "b > c ? " << (b > c) << std::endl;
    std::cout << "b <= d ? " << (b <= d) << std::endl;
    std::cout << "b >= d ? " << (b >= d) << std::endl;
    std::cout << "b == d ? " << (b == d) << std::endl;
    std::cout << "b != c ? " << (b != c) << std::endl;

    // Test des opérateurs arithmétiques
    std::cout << "b + c = " << b + c << std::endl;
    std::cout << "c - b = " << c - b << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    std::cout << "c / b = " << c / b << std::endl;

    // Test des opérateurs d'incrémentation et de décrémentation
    Fixed e;
    std::cout << "e = " << e << std::endl;
    std::cout << "++e = " << ++e << std::endl;
    std::cout << "e++ = " << e++ << std::endl;
    std::cout << "e après e++ = " << e << std::endl;
    std::cout << "--e = " << --e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "e après e-- = " << e << std::endl;

    // Test des fonctions min et max
    std::cout << "Min entre b et c : " << Fixed::min(b, c) << std::endl;
    std::cout << "Max entre b et c : " << Fixed::max(b, c) << std::endl;

    return 0;
}