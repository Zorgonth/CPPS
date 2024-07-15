/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:41 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/03/20 10:51:11 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::startup(int	flag)
{
	std::cout << std::endl;
	if (flag)
		std::cout << "Welcome to Your Phonebook\n" << std::endl;
	std::cout << "To use your Phonebook you can use one of these commands:\n" << std::endl;
	std::cout << "-Type ADD to add a contact to your Phonebook." << std::endl;
	std::cout << "-Type SEARCH to search for a contact in your Phonebook." << std::endl;
	std::cout << "-Type EXIT to exit your Phonebook." << std::endl;
	std::cout << "\nPlease remember that if you exit your Phonebook all the saved contacts will be gone forever!" << std::endl;
}


void	Phonebook::add(void)
{
	static int i;

	this->c[i % 8].init();
	this->c[i % 8].set(i % 8);
	i++;
}


void	Phonebook::display()
{
	int i = 0;
	std::cout << "             	PHONEBOOK             \n" << std::endl;
	while (i < 8)
	{
		this->c[i].view(i);
		i++;
	}
	std::cout << std::endl;
}

void	Phonebook::get_ind()
{
	int	input = -1;
	std::string	get;

	
	std::cout << "Please enter the contact's index: " << std::flush;
	while (1)
	{
		std::cin >> get;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (get[0] >= '0' && get[0] <= '8' && get.length() == 1)
			input = std::stoi(get);
		if (input != -1)
			break ;
		else
		{
			std::cout << "Invalid index! Try again." << std::endl;
			std::cin.clear();
		}
	}
	if (input != -1)
		this->c[input].display_all();
}

void	Phonebook::search()
{
	this->display();
	this->get_ind();
}