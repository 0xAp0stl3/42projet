/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:49 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:55:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain *_brain;

    public:
        Dog(void);
        Dog(const Dog &cp);
        ~Dog(void);

        Dog &operator=(const Dog &src);

        void makeSound(void) const;

        void getIdeas(void) const;
        void setIdeas(unsigned long index, std::string idea);
};

#endif