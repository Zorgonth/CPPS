/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:13:55 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/07 14:49:32 by sal-zuba         ###   ########.fr       */
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
	return ((float)this->getRawBits() / (float)(1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed &nbr) const
{
	if (this->toFloat() < nbr.toFloat())
		return true;
	else
		return false;	
}

bool Fixed::operator>(const Fixed &nbr) const
{
	if (this->toFloat() > nbr.toFloat())
		return true;
	else
		return false;	
}

bool Fixed::operator>=(const Fixed &nbr) const
{
	if (this->toFloat() >= nbr.toFloat())
		return true;
	else
		return false;	
}

bool Fixed::operator<=(const Fixed &nbr) const
{
	if (this->toFloat() <= nbr.toFloat())
		return true;
	else
		return false;	
}

bool Fixed::operator==(const Fixed &nbr) const
{
	if (this->toFloat() == nbr.toFloat())
		return true;
	else
		return false;	
}

bool Fixed::operator!=(const Fixed &nbr) const
{
	if (this->toFloat() != nbr.toFloat())
		return true;
	else
		return false;	
}

float Fixed::operator+(const Fixed &nbr) const
{
	return (this->toFloat() + nbr.toFloat());
}

float Fixed::operator-(const Fixed &nbr) const
{
	return (this->toFloat() - nbr.toFloat());
}

float Fixed::operator*(const Fixed &nbr) const
{
	return (this->toFloat() * nbr.toFloat());
}

float Fixed::operator/(const Fixed &nbr) const
{
	return (this->toFloat() / nbr.toFloat());
}

Fixed Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed	&Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1.getRawBits() > nbr2.getRawBits())
		return nbr2;
	else
		return nbr1;
}

Fixed	&Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1.getRawBits() < nbr2.getRawBits())
		return nbr2;
	else
		return nbr1;
}

const Fixed	&Fixed::min(const Fixed &nbr1,const  Fixed &nbr2)
{
	if (nbr1.getRawBits() > nbr2.getRawBits())
		return nbr2;
	else
		return nbr1;
}

const Fixed	&Fixed::max(const Fixed &nbr1,const  Fixed &nbr2)
{
	if (nbr1.getRawBits() < nbr2.getRawBits())
		return nbr2;
	else
		return nbr1;
}