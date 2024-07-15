/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:16:13 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/30 13:59:55 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "random";
	this->hp = 10;
	this->ad = 0;
	this->mana = 10;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->hp = 10;
	this->ad = 0;
	this->mana = 10;
	this->name = name;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cp)
{
	if (this != &cp)
	{
		this->name = cp.name;
		this->hp = cp.hp;
		this->ad = cp.ad;
		this->mana = cp.mana;
	}	
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &copy) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->setName(copy.getName());
	this->setAd(copy.getAd());
	this->setMana(copy.getMana());
	this->setHp(copy.getHp());
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

int ClapTrap::getAd(void) const
{
	return (this->ad);
}

int ClapTrap::getHp(void) const
{
	return (this->hp);
}

int ClapTrap::getMana(void) const
{
	return (this->mana);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setAd(int ad)
{
	if (ad >= 0)
		this->ad = ad;
	else
		std::cout << "Value can't be Negative!" << std::endl;
}

void ClapTrap::setHp(int hp)
{
	if (hp >= 0)
		this->hp = hp;
	else
		std::cout << "Value can't be Negative!" << std::endl;
}

void ClapTrap::setMana(int mana)
{
	if (mana >= 0)
		this->mana = mana;
	else
		std::cout << "ClapTrap "  << "Value can't be Negative!" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->getHp() > 0 && this->getMana() > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->getAd() << " points of damage!" << std::endl;
		this->setMana(this->getMana() - 1);
	}
	else
	{
		if (this->getHp() <= 0)
		{
			std::cout << "ClapTrap "  << this->name << " is dead already!" << std::endl;
			return ;
		}
		if (this->getMana() <= 0)
			std::cout << "ClapTrap "  << this->name << " has no mana left!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() > 0)
	{
		unsigned int	neu;
		if (amount > this->getHp())
			neu = 0;
		else
			neu = this->getHp() - amount;
		if (neu > 0)
		{
			this->setHp(neu);
			std::cout << "ClapTrap "  << this->name << " has taken " << amount << " points of damage!" << std::endl;
		}
		else
		{
			this->setHp(0);
			std::cout << "ClapTrap "  << this->name << " has been killed!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap "  << this->name << " is dead already!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHp() > 0 && this->getMana() > 0)
	{
		unsigned int	neu;
		neu = this->getHp() + amount;
		if (neu > 10)
			neu = 10;
		this->setHp(neu);
		std::cout << "ClapTrap "  << this->name << " has recovered " << amount << " health points!" << std::endl;
		this->setMana(this->getMana() - 1);
	}
	else
	{
		if (this->getHp() <= 0)
		{
			std::cout << "ClapTrap "  << this->name << " is dead already!" << std::endl;
			return ;
		}
		if (this->getMana() <= 0)
			std::cout << "ClapTrap "  << this->name << " has no mana left!" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, ClapTrap &member) {
	out << "Name: " << member.getName() << " HP: " << member.getHp() << " AD: " << member.getAd() << " Mana: " << member.getMana() << std::endl;
	return (out);
}