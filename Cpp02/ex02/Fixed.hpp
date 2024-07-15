/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:12 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/07 14:39:49 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	fix;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float fn);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		bool operator>(const Fixed &nbr) const;
		bool operator<(const Fixed &nbr) const;
		bool operator>=(const Fixed &nbr) const;
		bool operator<=(const Fixed &nbr) const;
		bool operator==(const Fixed &nbr) const;
		bool operator!=(const Fixed &nbr) const;
		
		float operator+(const Fixed &nbr) const;
		float operator-(const Fixed &nbr) const;
		float operator*(const Fixed &nbr) const;
		float operator/(const Fixed &nbr) const;
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		static const Fixed &min(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed &min(Fixed &nbr1, Fixed &nbr2);
		static const Fixed &max(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed &max(Fixed &nbr1, Fixed &nbr2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif