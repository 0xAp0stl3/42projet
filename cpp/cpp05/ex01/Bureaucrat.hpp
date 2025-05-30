/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:46 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/26 10:11:47 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
    private:
        const std::string	_name;
        int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(Bureaucrat& cp);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& src);

		void		setGrade(int grade);
		
		int			getGrade() const;
		std::string getName() const;
		
		void		increment(void);
		void		decrement(void);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	signForm(Form& f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);