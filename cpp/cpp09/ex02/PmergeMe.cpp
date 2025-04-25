/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:03:24 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 15:38:35 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {   
    }
    return (*this);
}

void PmergeMe::fusion(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    std::vector<int> winner, loosers;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] < arr[i + 1])
            {
                winner.push_back(arr[i]);
                loosers.push_back(arr[i + 1]);
            }
            else
            {
                winner.push_back(arr[i + 1]);
                loosers.push_back(arr[i]);
            }
        }
        else
            winner.push_back(arr[i]);
    }

    for (size_t i = 1; i < winner.size(); i++)
    {
        int key = winner[i];
        size_t j = i;
        while (j > 0 && winner[j - 1] > key)
        {
            winner[j] = winner[j - 1];
            --j;
        }
        winner[j] = key;
    }
    
    for (size_t i = 0; i < loosers.size(); i++)
    {
        int looser = loosers[i];
        std::vector<int>::iterator it = winner.begin();
        while (it != winner.end() && *it < looser)
        {
            it++;
        }
        winner.insert(it, looser);
    }
    arr = winner;
}

std::vector<int> PmergeMe::parseArguments(int ac, char** av)
{
    std::vector<int> arr;
    
    if (ac > 3001)
    {
            std::cerr << "Error: too much av\n";
            exit(1);
    }
    
    for (int i = 1; i < ac; i++)
    {
        std::string token = av[i];
        
        for (size_t j = 0; j < token.size(); j++) 
        {
            if (!std::isdigit(token[j])) 
            {
                std::cerr << "Erreur : Argument invalide \"" << token << "\"" << std::endl;
                throw std::invalid_argument("Non-numeric value encountered");
            }
        }
        int value = std::atoi(token.c_str());
        arr.push_back(value);
    }
    if (arr.empty())
        throw std::runtime_error("Erreur : Aucun nombre valide fourni.");
    return (arr);
}

