/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:56 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 10:17:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contact[8];
        int        _i;

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add(void);
        void    search(void);
        void    display(Contact contact);
        bool    displayContactList(void) const;
        void    promptAndDisplayContact(void); 
        Contact get_contact(int i);
};

#endif