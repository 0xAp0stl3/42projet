/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:32:33 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/26 10:39:11 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void): _name("default"), _signed(false), _grade_signed(1), _grade_exec(150)
{
    std::cout << "Form constructor default called" << std::endl;
}

Form::Form(const Form& cp): _name(cp._name), _signed(cp._signed), _grade_signed(cp._grade_signed), _grade_exec(cp._grade_exec)
{
    std::cout << "Form copie constructor called" << std::endl;    
}

Form::Form(const std::string& name, int grade_signed, int grade_exec) 
    :  _name(name), _signed(false), _grade_signed(grade_signed), _grade_exec(grade_exec)
{
    if (grade_signed < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_signed > 150 || grade_exec > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called for " << name << " with grade to sign " << grade_signed <<
    " with grade to execute " << grade_exec << std::endl;
}

Form &Form::operator=(const Form& src)
{
    std::cout << "Form assignation constructor called" << std::endl;
    if (this != &src)
        _signed = src._signed;
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName(void) const
{
    return (_name);
}
    
bool Form::getSigned(void) const
{
    return (_signed);
}

int Form::getGradeSigned(void) const
{
    return (_grade_signed);
}

int Form::getGradeExec(void) const
{
    return (_grade_exec);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade too high");
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _grade_signed)
        _signed = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form[name: " << obj.getName() << ", signed: " << obj.getSigned()
       << ", grade to sign: " << obj.getGradeSigned()
       << ", grade to execute: " << obj.getGradeExec() << "]";
    return (os);
}
