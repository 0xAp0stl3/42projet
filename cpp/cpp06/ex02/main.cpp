/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:37:01 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 12:01:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base* obj = generate();
	
	std::cout << "Identifying using pointer: ";
	identify(obj);
	
	std::cout << "Identifying using reference: ";
	identify(*obj);
	
	delete (obj);
    return (0);
}