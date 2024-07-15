/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:26:27 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/03/19 17:43:03 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	int	i;
	i = 0;
	Phonebook ph;
	std::string	input;

	ph.startup(1);
	while (1)
	{
		if (input == "ADD")
			ph.add();
		else if (input == "SEARCH")
			ph.search();
		else if (input ==  "EXIT" || std::cin.eof())
			break ;
		else if (input == "HELP")
			ph.startup(0);
		else
			if (i != 0)
				std::cout << "\nUnkown Command! type HELP to get a list of the available commands.\n" << std::endl;
		std::cout << "> " << std::flush;
		std::cin >> input;
		i++;
	}
	return (0);
}