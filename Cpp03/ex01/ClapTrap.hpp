/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:08:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/17 09:53:34 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int	hp;
		int	ad;
		int	mana;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &cp);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getHp(void) const;
		int getMana(void) const;
		int getAd(void) const;
		std::string getName(void) const;
		void setName(std::string name);
		void setMana(int energy);
		void setHp(int hp);
		void setAd(int ad);
};

std::ostream &operator<<(std::ostream &out, ClapTrap &member);

#endif