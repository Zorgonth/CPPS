/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:42:12 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/29 11:59:36 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Btc btc(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}
	else
		std::cout << RED << "Please enter the file name and only the file name!" << std::endl;
	return 0;
}