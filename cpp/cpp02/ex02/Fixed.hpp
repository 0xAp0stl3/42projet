/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:36:20 by mrocher           #+#    #+#             */
/*   Updated: 2024/10/10 08:41:57 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

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
		
		bool operator>(Fixed v) const;
		bool operator<(Fixed v) const;
		bool operator>=(Fixed v) const;
		bool operator<=(Fixed v) const;
		bool operator==(Fixed v) const;
		bool operator!=(Fixed v) const;
		
		float operator+(Fixed v) const;
		float operator-(Fixed v) const;
		float operator*(Fixed v) const;
		float operator/(Fixed v) const;
		
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int	toInt(void) const;
		static Fixed &min(Fixed &first, Fixed &sec);
		static const Fixed &min(Fixed const &first, Fixed const &sec);
		static Fixed &max(Fixed &first, Fixed &sec);
		static const Fixed &max(Fixed const &first, Fixed const &sec);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif