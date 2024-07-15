/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:08:25 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 09:58:00 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("Renekton");
	ClapTrap	b;

	b.setName("Ornn");

	a.setAd(7);
	b.setAd(1);

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.attack("Ornn");
	b.takeDamage(a.getAd());
	a.attack("Ornn");
	b.takeDamage(a.getAd());
	a.attack("Ornn");
	b.takeDamage(a.getAd());

	std::cout << std::endl;

	b.setHp(1);
	b.beRepaired(10);

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.takeDamage(b.getAd());
	b.attack("Renekton");
	a.attack("Ornn");
	b.takeDamage(a.getAd());
	a.beRepaired(4);
	a.attack("Ornn");
	b.takeDamage(a.getAd());
	std::cout << std::endl;
}