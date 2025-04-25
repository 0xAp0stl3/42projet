/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:51 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 11:49:53 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::IsInt(const std::string& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		if (i == 0 && (obj[i] == '-' || obj[i] == '+'))
			continue;
		if (!isdigit(obj[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::IsChar(const std::string& obj)
{
	if (obj.size() == 3 && obj[0] == '\'' && obj[2] == '\'')
        return (true);
    return (false);
}

bool ScalarConverter::IsFloat(const std::string& obj)
{
	if (obj.size() < 2 || obj[obj.size() - 1] != 'f')
		return (false);
	std::string core = obj.substr(0, obj.size() -1);
	return (IsDouble(core));
}

bool ScalarConverter::IsDouble(const std::string& obj)
{
	bool is_bool = false;
	for (size_t i = 0; i < obj.size(); i++)
	{
		if (i == 0 && (obj[i] == '+' || obj[i] == '-'))
			continue;
		if (obj[i] == '.')
		{
			if (is_bool)
				return (false);
			is_bool = (true);
		}
		else if (!isdigit(obj[i]))
			return (false);
	}
	return (is_bool);
}

bool ScalarConverter::IsPseudo(const std::string& obj)
{
	return (obj == "-inff" || obj == "+inff" || obj == "nanf" || obj == "-inf" \
		|| obj == "+inf" || obj == "nan");
}

bool ScalarConverter::IsNan(float obj)
{
	return (obj != obj);
}

void ScalarConverter::convert(std::string& obj)
{
	if (IsInt(obj))
	{
		long l = std::atol(obj.c_str());
		int	i = static_cast<int>(l);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		
		
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double " << d << ".0" << std::endl;
		return;
	}
	if (IsChar(obj))
	{
		char c = obj[1];
		int	i = static_cast<int>(c);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
		return;
	}
	if (IsFloat(obj))
	{
		float value = std::strtof(obj.c_str(), NULL);
		std::cout << "char: ";
		if (value >= 32 && value <= 126 && (value = static_cast<int>(value)))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() 
			|| IsNan(value))
		std::cout << "impossible" << std::endl;
		else
			std::cout << "" << static_cast<int>(value) << std::endl;
		std::cout << "float: " << value << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0 "<< std::endl;
		return;
	}
	if (IsDouble(obj))
	{
		double value = std::strtod(obj.c_str(), NULL);
		std::cout << "char: ";
		if (value >= 32 && value <= 126 && (value = static_cast<int>(value)))
			std::cout << "" << static_cast<char>(value) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() 
			|| IsNan(value))
			std::cout << "impossible" << std::endl;
		else
			std::cout << "" << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << value << ".0" << std::endl;
		return;
	}
	if (IsPseudo(obj))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (obj == "+inff" || obj == "-inff" || obj == "nanf")
		{
			std::cout << "float: " << obj << std::endl;
			std::cout << "double: " << obj.substr(0, obj.size() -1) << std::endl;
		}
		else
		{
			std::cout << "float: " << obj << "f" << std::endl;
			std::cout << "double: " << obj << std::endl;
		}
		return;
	}
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
}