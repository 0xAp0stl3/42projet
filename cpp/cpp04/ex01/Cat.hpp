/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:04:47 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 00:19:57 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *_brain;
        
    public:
        Cat(void);
        Cat(const Cat &cp);
        ~Cat(void);

        Cat &operator=(const Cat &src);

        void makeSound(void) const;

        void getIdeas(void) const;
        void setIdeas(unsigned long index, std::string idea);
};

#endif