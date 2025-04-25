/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:54:03 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 08:36:53 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int	a = 65;
	int	b = 75;
	
	std::cout << "Value of a: " << a << std::endl;
	std::cout << "Value of b: " << b << std::endl;
	
	std::cout << "The min between a and b: " << min<int>(a, b) << std::endl;
	std::cout << "The max between a and b: " << max<int>(a, b) << std::endl;
	std::cout << "Swap a<-->b" << std::endl;
	swap(a, b);
	
	std::cout << "Value of a: " << a << std::endl;
	std::cout << "Value of b: " << b << std::endl;
	return (0);
}