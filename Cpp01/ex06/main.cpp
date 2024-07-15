/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:15:48 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/21 16:53:11 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl comp;

	if (argc == 2)
	{
		comp.complain("DEBUG", std::string(argv[1]));
		comp.complain("INFO", std::string(argv[1]));
		comp.complain("WARNING", std::string(argv[1]));
		comp.complain("ERROR", std::string(argv[1]));
	}
	return (0);
}