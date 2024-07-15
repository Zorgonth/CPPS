/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:07:53 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 10:13:47 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHp(100);
	this->setAd(30);
	this->setMana(100);
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &og)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &og)
	{
		this->setName(og.getName());
		this->setHp(og.getHp());
		this->setAd(og.getAd());
		this->setMana(og.getMana());
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " HIGH FIVE GUYS! " << std::endl;
}