/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:29 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 12:38:51 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& force) :force(force)
{
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << this->name << " has been killed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with " << this->force.getType() << std::endl;
}