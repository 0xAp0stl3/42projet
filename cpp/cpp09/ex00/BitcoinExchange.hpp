/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:39:19 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/14 17:48:31 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _exchange;
        bool        validDate(const std::string& date) const;
        bool        validValue(const std::string& value) const;
        std::string displayDatePrevious(const std::string& date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cp);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& src);

        float   GetExchange(const std::string& date) const;

        void    loadCSV(const std::string& filename);
        void    loadAV(const char *filename);
};
