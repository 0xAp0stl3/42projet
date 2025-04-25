/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:32:31 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/26 10:17:44 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string	_name;
        bool				_signed;
		const int			_grade_signed;
		const int			_grade_exec;
	public:
		Form(void);
		Form(const Form& cp);
		Form(const std::string& name, int grade_signed, int grade_exec);
		~Form(void);
		
		Form& operator=(const Form& src);

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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
