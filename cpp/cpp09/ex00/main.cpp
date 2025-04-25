/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:39:01 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/14 18:11:52 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "Error: argument incorrect. Usage [./btc fichier.txt]" << std::endl;
        return (1);
    }
    BitcoinExchange btc;
        
    btc.loadCSV("data.csv");
    btc.loadAV(av[1]);
    return (0);
}