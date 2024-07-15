/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:53:08 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 11:54:37 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp)
{
	std::cout << "WrongCat copy contstructor called" << std::endl;
	this->setType(cp.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &og) {
	std::cout << "WrongCat operator assignment called" << std::endl;
	if (this != &og)
		this->setType(og.getType());
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Doesn't Meows" << std::endl;
}