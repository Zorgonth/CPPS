/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:59:04 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/05 14:11:27 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl comp;

	comp.complain("DEBUG");
	comp.complain("INFO");
	comp.complain("WARNING");
	comp.complain("ERROR");
	return (0);
}