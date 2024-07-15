/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:43:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 11:52:12 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &cp)
{
	std::cout << "Cat copy contstructor called" << std::endl;
	this->setType(cp.getType());
}

Cat &Cat::operator=(const Cat &og) {
	std::cout << "Cat operator assignment called" << std::endl;
	if (this != &og)
		this->setType(og.getType());
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meows" << std::endl;
}