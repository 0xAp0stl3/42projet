/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:32:33 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:44:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void): _name("default"), _signed(false), _grade_signed(1), _grade_exec(150)
{
    std::cout << "AForm constructor default called" << std::endl;
}

AForm::AForm(const AForm& cp): _name(cp._name), _signed(cp._signed), _grade_signed(cp._grade_signed), _grade_exec(cp._grade_exec)
{
    std::cout << "AForm copie constructor called" << std::endl;    
}

AForm::AForm(const std::string& name, int grade_signed, int grade_exec) 
    :  _name(name), _signed(false), _grade_signed(grade_signed), _grade_exec(grade_exec)
{
    if (grade_signed < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_signed > 150 || grade_exec > 150)
        throw GradeTooLowException();
    std::cout   << "AForm constructor called for " << name 
                << " with grade to sign " << grade_signed 
                << " with grade to execute " << grade_exec << std::endl;
}

AForm &AForm::operator=(const AForm& src)
{
    std::cout << "AForm assignation constructor called" << std::endl;
    if (this != &src)
        _signed = src._signed;
    return (*this);
}

AForm::~AForm(void)
{
}

const std::string& AForm::getName(void) const
{
    return (_name);
}
    
bool AForm::getSigned(void) const
{
    return (_signed);
}

int AForm::getGradeSigned(void) const
{
    return (_grade_signed);
}

int AForm::getGradeExec(void) const
{
    return (_grade_exec);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm: Grade too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm: Grade too high");
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _grade_signed)
        _signed = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "AForm[name: " << obj.getName() << ", signed: " << obj.getSigned()
       << ", grade to sign: " << obj.getGradeSigned()
       << ", grade to execute: " << obj.getGradeExec() << "]";
    return (os);
}
