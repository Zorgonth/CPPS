/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:08:30 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/03/20 10:19:35 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int	Contact::checker(std::string str)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
			flag = 1;
	}
	return (flag);
}

std::string Contact::in()
{
	std::string input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input.empty() || !std::cin.good() || !this->checker(input))
		{
			std::cin.clear();
			std::cout << "Invalid input! Try again." << std::endl;
		}
		else
			break ;
	}
	return (input);
}

std::string Contact::in_n()
{
	std::string input;
	bool	valid = true;
	while (1)
	{
		valid = true;
		std::getline(std::cin, input);
		if (input.empty() || !std::cin.good())
		{
			std::cin.clear();
			std::cout << "Invalid input! Try again." << std::endl;
			valid = false;
		}
		else
		{
			for (size_t i = 0; i < input.length(); i++)
			{
				if (!std::isdigit(input[i]))
					valid = false;
			}
			if (!valid)
				std::cout << "Invalid input! Try again." << std::endl;
			else
				break ;
		}
	}
	return (input);
}

void	Contact::init()
{
	std::cin.ignore();
	std::cout << "Please enter your contact's first name: " << std::flush;
	this->first_n = this->in();
	std::cout << "Please enter your contact's last name: " << std::flush;
	this->last_n = this->in();
	std::cout << "Please enter your contact's phone number: " << std::flush;
	this->number = this->in_n();
	std::cout << "Please enter your contact's nickname: " << std::flush;
	this->nick_n = this->in();
	std::cout << "Please enter your contact's darkest secret: " << std::flush;
	this->secret = this->in();
	std::cout << "Contact Has been added!" << std::endl;
}

void	Contact::set(int i)
{
	this->ind = i;
}

void	Contact::view(int ind)
{
	std::string tmp;
	
	if (this->first_n.empty())
		return ;
	std::cout << "|" << std::setw(10) << std::right << ind << std::flush;
	if (this->first_n.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << (this->first_n.substr(0, 9) + ".") << std::flush;
	else
		std::cout << "|" << std::setw(10) << std::right << (this->first_n) << std::flush;
	if (this->last_n.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << (this->last_n.substr(0, 9) + ".") << std::flush;
	else
		std::cout << "|" << std::setw(10) << std::right << (this->last_n) << std::flush;
	if (this->nick_n.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << (this->nick_n.substr(0, 9) + ".") << std::flush;
	else
		std::cout << "|" << std::setw(10) << std::right << (this->nick_n) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display_all()
{
	if (this->first_n.empty() || this->last_n.empty())
	{
		std::cout << "This Contact does not exit!\n" << std::endl;
		return ;
	}
	std::cout << "\nContact  #" << this->ind << std::endl;
	std::cout << "First name:\t" << this->first_n << std::endl;
	std::cout << "Last name:\t" << this->last_n << std::endl;
	std::cout << "Phone number:\t" << this->number << std::endl;
	std::cout << "Nickname:\t" << this->nick_n << std::endl;
	std::cout << "Darkest secret:\t" << this->secret << std::endl;
	std::cout << std::endl;
}

