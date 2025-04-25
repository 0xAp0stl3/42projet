/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:48 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 12:10:37 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cp);
		ScalarConverter &operator=(const ScalarConverter& src);
		~ScalarConverter();
		
		static bool IsInt(const std::string& obj);
		static bool IsChar(const std::string& obj);
		static bool IsDouble(const std::string& obj);
		static bool IsFloat(const std::string& obj);
		static bool IsPseudo(const std::string& obj);
		static bool IsNan(float obj);
	public:
		static void convert(std::string& obj);
};

#endif