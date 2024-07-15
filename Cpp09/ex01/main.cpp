/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:21:39 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/06 13:26:24 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		RPN rpn(argv[1]);
	else
		std::cout << RED << "PLEASE Input All And Only The Needed Arguments!" << DEFAULT << std::endl;
	return 1;
}