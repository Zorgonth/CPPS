/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:33:52 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/24 10:53:51 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fix = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->fix = copy.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	this->fix = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->fix;
}

void	Fixed::setRawBits( int const raw)
{
	this->fix = raw;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << this->bits);
}

Fixed::Fixed(const float fn)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(fn * (float)(1 << this->bits)));
}

float Fixed::toFloat(void) const
{
	return (((float)this->getRawBits()) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}