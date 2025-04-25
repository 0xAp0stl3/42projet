/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:55:49 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 10:58:51 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Usage [./RPN '8 8 *']" << std::endl;
        return (1);
    }
    RPN rpn;
    
    rpn.processArgument(av[1]);
    try
    {
        double resutl = rpn.calculate(av[1]);
        std::cout << resutl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}