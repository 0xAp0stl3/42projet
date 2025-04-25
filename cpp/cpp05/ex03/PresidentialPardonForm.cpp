/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:46:36 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:57:05 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cp)
    : AForm("PresidentialPardonForm", 25, 5), _target(cp._target)
{
    std::cout << "PresidentialPardonForm copie constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    std::cout << "PresidentialPardonForm assignation constructor called" << std::endl;
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Macron" << std::endl;
}