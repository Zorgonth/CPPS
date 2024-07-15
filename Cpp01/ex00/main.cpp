/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:36:21 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 13:41:40 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	stack("Bob");
	Zombie	*heap = new Zombie("Jack");

	randomChump("Steve");
	stack.announce();
	heap->announce();
	delete heap;
	return (0);
}