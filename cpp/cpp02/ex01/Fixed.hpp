/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:36:20 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 08:41:05 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int _fract_bits_value;
	public:
		Fixed();
		Fixed(const Fixed& cp);
		Fixed(const int conv);
		Fixed(const float conv);
		~Fixed();
		
		Fixed &operator=(const Fixed &src);	
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif