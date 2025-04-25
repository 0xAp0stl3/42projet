/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:49:48 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:52:53 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include <cstdio>
# include <cstdlib>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal &cp);
        virtual ~AAnimal(void);

        AAnimal &operator=(const AAnimal &src);

        std::string getType(void) const;
        
        virtual void makeSound(void) const = 0;
};

#endif