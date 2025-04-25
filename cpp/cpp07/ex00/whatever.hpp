/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:46:25 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 08:35:49 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <iostream>

template< typename T >
T const&	min(T const& x, T const& y)
{
	return (x<=y ? x : y);
}

template< typename T >
T const&	max(T const& x, T const& y)
{
	return (x>=y ? x : y);
}

template< typename T >
void	swap(T& a, T& b)
{
	T	temp;
	
	temp = a;
	a = b;
	b = temp;
}