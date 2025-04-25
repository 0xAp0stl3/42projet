/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:16:18 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 08:42:58 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	printInt(int x)
{
	std::cout << x << " ";
}

template<typename T>
void	printElement(T const& elem)
{
	std::cout << elem << " ";
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(array) / sizeof(array[0]);
	
	std::cout << "Int array: ";
	iter(array, len, printInt);
	std::cout << std::endl;
	
	std::string strArray[] = {"Hello", "World", "!"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
	
	std::cout << "String array: ";
	iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

    return (0);
}