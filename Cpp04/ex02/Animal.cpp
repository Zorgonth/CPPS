/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:31:40 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 11:36:12 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
	std::cout << "Animal copy contstructor called" << std::endl;
	this->setType(cp.getType());
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void Animal::setType(std::string type) {
	this->type = type;
}

Animal &Animal::operator=(const Animal &og) {
	std::cout << "Animal operator assignment called" << std::endl;
	if (this != &og)
		this->setType(og.getType());
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "Animal making noise" << std::endl;
}