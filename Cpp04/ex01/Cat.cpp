/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:43:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/26 14:28:00 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat::Cat(const Cat &cp) : Animal(cp), brain(NULL)
{
	std::cout << "Cat copy contstructor called" << std::endl;
	if (this != &cp) {
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.GetBrain());	
	}
}

Cat &Cat::operator=(const Cat &og) {
	std::cout << "Cat operator assignment called" << std::endl;
	if (this != &og) {
		this->setType(og.getType());
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*og.GetBrain());
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meows" << std::endl;
}

void Cat::SetBrain(Brain *Brain)
{
	this->brain = Brain;
}

Brain *Cat::GetBrain(void) const
{
	return (this->brain);
}
