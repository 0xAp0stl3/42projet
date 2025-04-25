/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:07:36 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/15 01:14:23 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain &cp);
        virtual ~Brain(void);

        Brain &operator=(const Brain &src);

        std::string _ideas[100];
        
        const std::string getIdeas(unsigned long index) const;
        void setIdeas(unsigned long index, std::string idea);
};

#endif