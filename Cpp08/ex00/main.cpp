/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:23:43 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 13:52:52 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NonExistingValue::what() const throw()
{
	return "The Value That Has Been Submited Is Not In The Container!";
}

int main()
{
	try
	{
		std::vector<int> container;

		container.push_back(1);
		container.push_back(2);
		container.push_back(3);
		container.push_back(4);
		container.push_back(5);
		easyfind(container, 1);
		easyfind(container, 9);
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;	
	}
	return 0;
}