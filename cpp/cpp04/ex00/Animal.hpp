/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:24 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/14 22:24:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(const Animal &cp);
        virtual ~Animal(void);

        Animal &operator=(const Animal &src);

        std::string getType(void) const;
        
        virtual void makeSound(void) const;
};

#endif