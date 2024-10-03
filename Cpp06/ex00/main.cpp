/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:26:11 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 10:38:59 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter& converter = ScalarConverter::getInstance();
	if (argc != 2)
	{
		std::cout << "Please enter a value for the converter to convert! Make sure it's one value only!" << std::endl;
		return 1;
	}
	converter.convert(argv[1]);
	return 0;
}