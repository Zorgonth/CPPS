/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:47:11 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 11:04:48 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int  main()
{
	Array<std::string> list(2);

	list[0] = "Hello";
	list[1] = "World";

	for (int i = 0;i < 2;i++)
		std::cout << list[i] << std::endl;
	std::cout << std::endl;
	Array<std::string> copy(list);

	for (int i = 0;i < 2;i++)
		std::cout << copy[i] << std::endl;
	
	copy[0] = "?????";
	std::cout << std::endl;
	std::cout << "The original list:" << std::endl; ;
	for (int i = 0;i < 2;i++)
		std::cout << list[i] << std::endl;
	std::cout << std::endl;
	std::cout << "The changed copy:" << std::endl;;
	for (int i = 0;i < 2;i++)
		std::cout << copy[i] << std::endl;
	return 0;
}