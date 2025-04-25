/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:18:07 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 08:39:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _fract_bits_value;
	public:
		Fixed();
		Fixed(const Fixed& cp);
		~Fixed();
		
		Fixed &operator=(const Fixed &src);
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif