/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:19:07 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 13:08:01 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
void addRange(Span& sp, T begin, T end)
{
    for (T it = begin; it != end; ++it)
    {
        try
        {
            sp.addNumber(*it);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
    }
}

int main()
{
    Span sp(5);
    int vec[] = {11, 5, 366, 45, 52};
    unsigned int len = sizeof(vec) / sizeof(vec[0]);
    std::vector<int> values(vec, vec + len);
    try
    {
        addRange(sp, values.begin(), values.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        sp.addNumber(8);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    return (0);
}