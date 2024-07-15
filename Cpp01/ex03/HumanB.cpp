/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 12:39:02 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->force = NULL;
}

HumanB::~HumanB()
{
	std::cout << this->name << " has been killed" << std::endl;
}

void	HumanB::attack()
{
	if (this->force)
		std::cout << this->name << " attacks with " << this->force->getType() << std::endl;
	else
		std::cout << this->name << " has no Weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &force)
{
	this->force = &force;
}