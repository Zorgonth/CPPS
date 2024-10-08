/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:14:39 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 13:15:57 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Serializer& ser = Serializer::getInstance();
	Data	*raw;
	Data	ptr;
	uintptr_t serialized;
	ptr.name = "Student";
	ptr.number = 42;
	ptr.next = NULL;

	serialized = ser.serialize(&ptr);
	std::cout << serialized << std::endl;
	raw = ser.deserialize(serialized);
	std::cout << raw->name << std::endl;
	std::cout << raw->number << std::endl;
}