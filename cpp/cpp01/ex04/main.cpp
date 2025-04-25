/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:48:38 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/08 08:51:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceOccurence(std::string &content, std::string &s1, std::string &s2)
{
	std::string newContent;
	size_t	startPos = 0;
	size_t	foundPos;
	
	while ((foundPos = content.find(s1, startPos)) != std::string::npos)
	{
		newContent.append(content, startPos, foundPos - startPos);
		newContent.append(s2);
		startPos = foundPos + s1.length();
	}
	newContent.append(content, startPos, content.length() - startPos);
	return (newContent);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	
	std::string filename = av[1];
	std::string s1 		= av[2];
	std::string s2 		= av[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << " for reading." << std::endl;
		return (1);
	}

	std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
	inFile.close();
	std::string newContent = replaceOccurence(content, s1, s2);
	std::string output = filename + ".replace";
	std::ofstream outFile(output.c_str());
	
	if (!outFile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << " for reading." << std::endl;
		return (1);
	}
	outFile << newContent;
	outFile.close();
	std::cout << "Replacement complete. Output written to " << output << std::endl;
	return (0);	
}