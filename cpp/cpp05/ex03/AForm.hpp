/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:32:31 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/29 15:29:54 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    protected:
        const std::string	_name;
        bool				_signed;
		const int			_grade_signed;
		const int			_grade_exec;
	public:
		AForm(void);
		AForm(const AForm& cp);
		AForm(const std::string& name, int grade_signed, int grade_exec);
		virtual ~AForm(void) = 0;
		
		AForm& operator=(const AForm& src);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSigned(void) const;
		int					getGradeExec(void) const;
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
