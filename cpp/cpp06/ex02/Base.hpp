/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:48 by mrocher           #+#    #+#             */
/*   Updated: 2024/12/02 12:26:42 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
  public:
    virtual ~Base() = 0;
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif