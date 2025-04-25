/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:24:30 by mrocher           #+#    #+#             */
/*   Updated: 2024/11/29 16:54:07 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& cp);
        ~Intern();
        
        Intern& operator=(const Intern& src);

        AForm *makeForm(const std::string name_form, const std::string target_form);
};