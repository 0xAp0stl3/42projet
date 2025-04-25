/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:02:25 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 09:45:05 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int    main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; av[i]; i++)
        {
            for (int j = 0; av[i][j]; j++)
                std::cout << (char) toupper(av[i][j]);
            if (i < ac - 1)
                std::cout << " ";
        }
    }
    std::cout << std::endl;
    return (0);
}