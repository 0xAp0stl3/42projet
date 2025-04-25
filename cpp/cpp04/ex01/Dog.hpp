/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:49 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:19:52 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
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