/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:52:20 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 12:00:53 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &cp)
{
	std::cout << "Dog copy contstructor called" << std::endl;
	this->setType(cp.getType());
}

Dog &Dog::operator=(const Dog &og) {
	std::cout << "Dog operator assignment called" << std::endl;
	if (this != &og)
		this->setType(og.getType());
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Barks" << std::endl;
}