/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:53:42 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/14 13:34:02 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main()
{
   //  const Animal* dog = new Dog();
	// std::cout << std::endl;
   //  const Animal* cat = new Cat();
	// std::cout << std::endl;

   //  delete dog;
	// std::cout << std::endl;

   //  delete cat;
	// std::cout << std::endl;

	Dog basic;

	Dog tmp = basic;
    std::cout << "----------------------------" << std::endl;
	// Dog ogDog;
   //  {
   //  	std::cout << std::endl;
	//     Dog dog1 = ogDog;
	// 	ogDog.GetBrain()->SetIdea(0, "Hello");
	// 	std::cout << "Copy : " << dog1.GetBrain()->GetIdea(0) << std::endl;
	// 	std::cout << "Initial: " << ogDog.GetBrain()->GetIdea(0) << std::endl;
	// 	Dog tmp = ogDog;
	// 	ogDog.GetBrain()->SetIdea(1, "World");
	// 	std::cout << "Copy0 : " << dog1.GetBrain()->GetIdea(0) << std::endl;
	// 	std::cout << "Copy1 : " << tmp.GetBrain()->GetIdea(0) << std::endl;
	// 	std::cout << "Initial: " << ogDog.GetBrain()->GetIdea(0) << std::endl;

	// 	std::cout << "Copy0 : " << dog1.GetBrain()->GetIdea(1) << std::endl;
	// 	std::cout << "Copy1 : " << tmp.GetBrain()->GetIdea(1) << std::endl;
	// 	std::cout << "Initial: " << ogDog.GetBrain()->GetIdea(1) << std::endl;

	// 	ogDog.GetBrain()->SetIdea(-1, "hi");
	// 	ogDog.GetBrain()->SetIdea(101, "hi");
	// }
	std::cout << "----------------------------" << std::endl;

   //  const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
   //  std::cout << std::endl;
	// for (int i = 0; i < 4; i++)
	// {
   //    delete animals[i];
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// Cat *zok = new Cat();
	// Cat *zok1 = new Cat(*zok);
	
	// delete zok;
	// delete zok1;
   return 0;
}