/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:56:52 by mrocher           #+#    #+#             */
/*   Updated: 2024/12/19 12:50:32 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0)
{
    std::cout << "Span constructor default called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span& cp) : _n(cp._n)
{
    std::cout << "Span constructor copie called" << std::endl;
}

Span &Span::operator=(const Span& src)
{
    std::cout << "Span constructor assignation called" << std::endl;
    if (this != &src)
        _n = src._n;
    return (*this);
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;    
}

void    Span::addNumber(int number)
{
    if (_numbers.size() >= _n)
        throw AddErreurException();
    _numbers.push_back(number);
}

const char *Span::AddErreurException::what() const throw()
{
    return ("Erreur: the maximum n numbers is already add.");
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw LogicException();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min_span = INT_MAX;
    for (size_t i = 0; i < sorted.size(); i++)
        min_span = std::min(min_span, sorted[i] - sorted[i - 1]);
    return (min_span);
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw LogicException();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int longest = *std::max_element(_numbers.begin(), _numbers.end());

    return (longest - min);
}

const char *Span::LogicException::what() const throw()
{
    return ("Erreur: vous devez avoir minimum 2 nombres.");
}
