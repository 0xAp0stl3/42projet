/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:45:50 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/29 15:48:48 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cp)
    : AForm("ShrubberyCreationForm", 145, 137), _target(cp._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    std::cout << "ShrubberyCreationForm assignation called" << std::endl;
    if (this != &src)
    {
        AForm::operator=(src);
        _target = src._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();

    std::ostringstream filename;
    filename << _target << "_shrubbery";
    std::ofstream file(filename.str().c_str());
    
    if (!file.is_open())
        throw std::ios_base::failure("Error: Failed to open file");
    file << "      /\\\n";
    file << "     /\\*\\\n";
    file << "    /\\O\\*\\\n";
    file << "   /*/\\/\\/\\\n";
    file << "  /\\O\\/\\*\\/\\\n";
    file << " /\\*\\/\\*\\/\\/\\\n";
    file << "/\\O\\/\\/*/\\/O/\\\n";
    file << "      ||\n";
    file << "      ||\n";
    file.close();
    std::cout << "Shrubbery created in " << filename.str() << std::endl;
}
