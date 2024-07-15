/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:53:42 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/23 12:06:24 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nType is: " << dog->getType() << std::endl;
	std::cout << "Type is: " << cat->getType() << "\n" << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;
	
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << std::endl;
	
	WrongAnimal wrongAnimal;
	std::cout << wrongAnimal.getType() << std::endl;
	wrongAnimal.makeSound();
	std::cout << std::endl;
	
	delete wrongCat;
	return (0);
}