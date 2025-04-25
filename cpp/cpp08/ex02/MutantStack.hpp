/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:52:03 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 12:59:19 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        
        MutantStack(): std::stack<T, Container>() {}
        MutantStack(const MutantStack& cp) : std::stack<T, Container>(cp) {}
        ~MutantStack() {}

        MutantStack& operator=(const MutantStack& src)
        {
            if (this != &src)
                std::stack<T, Container>::operator=(src);
            return (*this);
        }

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }

        const_iterator begin() const
        {
            return (this->c.begin());
        }

        const_iterator end() const
        {
            return (this->c.end());
        }

        reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }
        
        reverse_iterator rend()
        {
            return (this->c.rend());
        }
        
        const_reverse_iterator rbegin() const
        {
            return (this->c.rbegin());
        }

        const_reverse_iterator rend() const
        {
            return (this->c.rend());
        }
};