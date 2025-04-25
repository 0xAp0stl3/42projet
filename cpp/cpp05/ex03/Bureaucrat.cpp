/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:43 by mrocher           #+#    #+#             */
/*   Updated: 2025/04/22 09:51:30 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat constructor called for " << name << " with grade " << 
    grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& cp): _name(cp._name), _grade(cp._grade)
{
    std::cout << "Bureaucrat copie constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cout << "Bureaucrat assignation constructor called" << std::endl;
    if (this != &src)
        _grade = src._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

void Bureaucrat::increment(void)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrement(void)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat: Grade too low");
}

void Bureaucrat::signForm(AForm& f)
{
    try 
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    } 
    catch (const AForm::GradeTooLowException& e) 
    {
        std::cout << getName() << " couldn't sign " << f.getName()
        << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        std::cout << _name << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    catch (const std::exception& e)
    {
        std::cerr << _name << " couldn't execute " << form.getName() 
        << " because " << e.what() << std::endl;   
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << "Bureaucrat[name: " << obj.getName() << ", grade: " << obj.getGrade() << "]";
    return (os);
}