/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:52:46 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/29 16:11:33 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AForm;

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

		void	signForm(AForm& f);
		void	executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);