/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:28:45 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 12:39:18 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << this->type << "Has been destoryed" << std::endl;
}

void Weapon::setType(const std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType(void)
{
	return (this->type);
}