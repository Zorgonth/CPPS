/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:31:46 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/30 14:00:22 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{

	ScavTrap	ScavTrapA("Robot A");
	ScavTrap	ScavTrapB("Robot B");

	// std::cout << std::endl;

	std::cout << ScavTrapA << ScavTrapB << std::endl;

	// ScavTrapA.attack("Robot B");
	// ScavTrapB.takeDamage(ScavTrapA.getAd());

	// std::cout << std::endl;
	// std::cout << ScavTrapA << ScavTrapB << std::endl;

	// ScavTrapB.beRepaired(5);
	
	// std::cout << std::endl;
	// std::cout << ScavTrapA << ScavTrapB << std::endl;
	
	// ScavTrapB.guardGate();
	// std::cout << std::endl;

	return (0);
}