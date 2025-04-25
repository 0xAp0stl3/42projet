/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:43:47 by mrocher           #+#    #+#             */
/*   Updated: 2024/12/19 10:47:30 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <list>
#include <string>
#include <iostream>

template <typename T>
void easyfind(T list, int occurrence)
{
    std::list<int>::iterator it;
    it  = std::find(list.begin(), list.end(), occurrence);
    if (it != list.end())
        std::cout << "Occurrence de " << occurrence << " trouvé." << std::endl;
    else
        std::cout << "Aucune occurrence de " << occurrence << " dans la liste." << std::endl;
}