/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:16:15 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/23 08:40:14 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template< typename T, typename Func>
void	iter(T* array, size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}