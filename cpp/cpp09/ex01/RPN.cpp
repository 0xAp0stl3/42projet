/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:55:51 by mrocher           #+#    #+#             */
/*   Updated: 2025/01/16 11:19:27 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN &RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
    }
    return (*this);
}

RPN::~RPN() {}

bool RPN::validValue(const std::string& value)
{
    if (value.empty())
        return (false);
    int val = std::strtol(value.c_str(), NULL, 10);
    if (val > 10)
    {
        std::cerr << "Enter number under or equal a 10" << std::endl;
        return (false);
    }
    return (true);
}

void RPN::processArgument(const char *av)
{
    std::stringstream ss(av);
    std::string value;

    while (ss >> value)
    {
        if (!validValue(value))
            exit(1);
    }
}

bool RPN::isOp(const std::string& op) const
{
    return (op == "+" || op == "-" || op == "/" || op == "*");
}

double RPN::applyOp(double a, double b, const std::string& op) const
{
    if (op == "+")
        return (a + b);
    if (op == "-")
        return (a - b);
    if (op == "*")
        return (a * b);
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division 0");
        return (a / b);
    }
    throw std::runtime_error("Error: operation inconnue");
}

double RPN::calculate(const char *op)
{
    std::stack<double> stack;
    std::stringstream ss(op);
    std::string tok;

    while (ss >> tok)
    {
        if (std::isdigit(tok[0]) || (tok[0] == '-' && tok.size() > 1))
            stack.push(std::strtod(tok.c_str(), NULL));
        else if (isOp(tok))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough number");
            
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            double result = applyOp(a, b, tok);
            stack.push(result);
        }
        else
            throw std::runtime_error("Error: op");
    }
    if (stack.size() < 1)
        throw std::runtime_error("Error: empty");
    else if (stack.size() <= 2)
        throw std::runtime_error("Error: not op");
    return (stack.top());
}