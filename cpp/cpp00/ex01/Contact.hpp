/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/02 08:40:12 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact 
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _secret;

    public:
        Contact(void);
        ~Contact(void);
        
        std::string get_first_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nickname(void) const;
        std::string get_phone_number(void) const;
        std::string get_secret(void) const;
        void        set_first_name(std::string str);
        void        set_last_name(std::string str);
        void        set_nickname(std::string str);
        void        set_phone_number(std::string str);
        void        set_secret(std::string str);
        
};

#endif