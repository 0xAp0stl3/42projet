/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:03:26 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 15:43:32 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        PmergeMe& operator= (const PmergeMe& src);

        void fusion(std::vector<int>& arr);
        std::vector<int> parseArguments(int ac, char** av);
};