/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:24:28 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:52:12 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& cp)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = cp;
}

Intern &Intern::operator=(const Intern& src)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this != &src)
    {
    }
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *makeShrubberyCreationForm(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomyRequestForm(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makePresidentialPardonForm(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string name_form, const std::string target_form)
{
    AForm *(*all_forms[])(const std::string target) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    for (int i = 0; i < 3; i++)
    {
        if (name_form == forms[i])
        {
            std::cout << "Intern creates " << name_form << " now" << std::endl;
            return (all_forms[i](target_form));
        }
    }
    std::cout << "Intern can't not create a form called" << name_form << std::endl;
    return (NULL);
}