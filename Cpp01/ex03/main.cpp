/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 12:39:06 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club = Weapon("Serated dirk");
	HumanA bob("Renekton", club);
	bob.attack();
	club.setType("Profane hydra");
	bob.attack();
	HumanB jim("Ornn");
	jim.attack();
	jim.setWeapon(club);
	club.setType("Hammer ");
	jim.attack();
}