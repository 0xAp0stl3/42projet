/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:48 by mrocher           #+#    #+#             */
/*   Updated: 2024/12/02 12:26:42 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

typedef size_t uintptr_t;

struct Data
{
	int obj;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cp);
		~Serializer();
		Serializer& operator=(const Serializer& src);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif