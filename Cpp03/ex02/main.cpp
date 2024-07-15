/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:31:46 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/23 13:36:29 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	A("John");
	FragTrap	B("Jimmy");
	std::cout << std::endl;
	std::cout << A << B << std::endl;

	A.attack("Jimmy");
	B.takeDamage(A.getAd());
	std::cout << std::endl;

	std::cout << A << B << std::endl;

	B.beRepaired(5);
	std::cout << std::endl;
	std::cout << A << B << std::endl;

	B.highFivesGuys();
	std::cout << std::endl;

	return (0);
}