/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:03:22 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 15:55:06 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) 
{
    if (ac < 2) 
    {
        std::cerr << "Usage: " << av[0] << " number1 number2 number3 ..." << std::endl;
        return (1);
    }

    PmergeMe merge;
    clock_t timed = std::clock();

    try 
    {
        std::vector<int> arr = merge.parseArguments(ac, av);

        std::cout << "Tableau original : ";
        for (size_t i = 0; i < arr.size(); i++) 
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        merge.fusion(arr);

        std::cout << "Tableau trié : ";
        for (size_t i = 0; i < arr.size(); i++) 
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        timed = std::clock() - timed;
        std::cout << "Time to process a range " << ac - 1 << " with [std::vector]: " 
            << (float)timed/CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}