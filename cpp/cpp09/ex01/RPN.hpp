/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:55:53 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 11:07:05 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

class RPN
{
    private:
        bool    isOp(const std::string& op) const;
        double  applyOp(double a, double b, const std::string& op) const;
        bool    validValue(const std::string& value);
    public:
        RPN();
        ~RPN();

        RPN &operator=(const RPN& src);

        void processArgument(const char *av);
        double calculate(const char *op);
};