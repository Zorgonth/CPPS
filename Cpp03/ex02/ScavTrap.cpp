/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:33:06 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 09:51:46 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHp(100);
	this->setAd(20);
	this->setMana(50);
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &og)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &og)
	{
		this->setName(og.getName());
		this->setHp(og.getHp());
		this->setAd(og.getAd());
		this->setMana(og.getMana());
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAd() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " is now in gate keeper mode." << std::endl;
}