/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:33:54 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/14 17:52:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp) 
{
    _exchange = cp._exchange;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
    {
        _exchange = src._exchange;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    for (size_t i = 0; i < date.size(); i++)
    {
        if ((i != 4 && i != 7) && !std::isdigit(date[i]))
            return (false);
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (month == 2)
    {
        bool by = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (by ? 29 : 28))
            return (false);
    }
    return (true);
}

bool BitcoinExchange::validValue(const std::string& value) const
{
    char *end;
    double val = std::strtod(value.c_str(), &end);
    
    if (*end != '\0')
        return (false);
    if (val < 0 || val > 1000)
        return (false);
    return (true);
}

std::string BitcoinExchange::displayDatePrevious(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _exchange.lower_bound(date);
    
    if (it != _exchange.end() && it->first == date)
        return (date);

    if (it == _exchange.begin())
    {
        std::cerr << "Error: no avaible previous date for " << date << std::endl;
        return ("");
    }

    --it;
    return (it->first);
}

float BitcoinExchange::GetExchange(const std::string& date) const 
{
    std::string closeDate = displayDatePrevious(date);
    if (closeDate.empty())
        return (-1);
    return (_exchange.at(closeDate));
}

void    BitcoinExchange::loadCSV(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: failed to open file" << filename << std::endl;
        return;
    }

    std::string line;
    bool firstline = true;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;
        float rate;
        if (firstline)
        {
            firstline = false;
            continue;
        }
        std::getline(ss, date, ',');
        std::getline(ss, rateStr, ',');

        try
        {
            rate = std::strtod(rateStr.c_str(), NULL);
            _exchange[date] = rate;
        }
        catch(...)
        {
            std::cerr << "Error conversion line: " << line << std::endl;   
        }
    }
    file.close();
}

void    BitcoinExchange::loadAV(const char *filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: failed to open file" << filename << std::endl;
        return;
    }

    std::string line;
    bool firstline = true;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, value;
        float resultat;
        if (firstline)
        {
            firstline = false;
            continue;
        }
        std::getline(ss, date, '|');
        std::getline(ss, value, '|');

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);

        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        
        if (!validDate(date))
        {
            std::cerr << "Error: date invalid format: " << date << std::endl;
            continue;
        }
        if (!validValue(value))
        {
            std::cerr << "Error: value invalid format: " << value << std::endl;
            continue;
        }
        float exchange = GetExchange(date);
        if (exchange == -1)
            continue;
        float valeurFloat = std::strtod(value.c_str(), NULL);
        resultat = valeurFloat * exchange;
        std::cout << "Le " << date << ", " << valeurFloat 
            << " BTC valaient " << resultat << " $" << std::endl;
    }
    file.close();
}


