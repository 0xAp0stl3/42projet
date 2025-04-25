/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:48:27 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 12:53:30 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

class Span
{
    private:
        unsigned int    _n;
        std::vector<int>  _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& cp);
        ~Span();

        Span& operator=(const Span& src);

        void    addNumber(int number);

        class   AddErreurException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        int   shortestSpan() const;
        int   longestSpan() const;

        class LogicException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};