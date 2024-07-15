/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:52:45 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 11:52:58 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
	std::cout << "WrongAnimal copy contstructor called" << std::endl;
	this->setType(cp.getType());
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &og) {
	std::cout << "WrongAnimal operator assignment called" << std::endl;
	if (this != &og)
		this->setType(og.getType());
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal making noise" << std::endl;
}