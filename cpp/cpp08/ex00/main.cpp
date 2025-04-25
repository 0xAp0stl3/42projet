/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:25:28 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 12:51:35 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::list<int> lst1;

    lst1.push_back(2);
    lst1.push_back(25);
    lst1.push_back(7);
    lst1.push_back(56);
    lst1.push_back(76);
    lst1.push_back(4);
    
    easyfind(lst1, 12);
    return (0);
}