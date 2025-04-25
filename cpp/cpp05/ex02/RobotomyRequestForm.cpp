/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:46:13 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/29 16:19:47 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cp)
    : AForm("RobotomyRequestForm", 72, 45), _target(cp._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << "* BRRRRZZZZZ ... BRRRRRRRZZZZZ ... VRRRRRRRR *" << std::endl;
    std::srand(std::time(0));
    
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " has failed!" << std::endl;
}