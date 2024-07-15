/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:52:20 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/26 14:22:47 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Dog::Dog(const Dog &cp) : Animal(cp), brain(NULL)
{
	std::cout << "Dog copy contstructor called" << std::endl;
	if ( this != &cp) {
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.GetBrain());
	}
}

Dog &Dog::operator=(const Dog &og) {
	std::cout << "Dog operator assignment called" << std::endl;
	if (this != &og) {
		this->setType(og.getType());
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*og.GetBrain());
	}
	return *this;

}

void Dog::makeSound(void) const {
	std::cout << "Barks" << std::endl;
}

void Dog::SetBrain(Brain *Brain)
{
	this->brain = Brain;
}

Brain *Dog::GetBrain(void) const
{
	return (this->brain);
}