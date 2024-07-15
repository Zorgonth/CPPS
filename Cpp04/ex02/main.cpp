/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:53:42 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:09 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *animal[10];
	for (int i = 0;i < 10;i++)
	{
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (int i = 0;i < 10;i++)
	{
		std::cout << "Animal : " << animal[i]->getType() << std::endl;
		animal[i]->makeSound();
		std::cout << std::endl;
	}
	
}