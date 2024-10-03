/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:52 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 13:19:59 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <ctime>


Base* generate(void)
{
	std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(1, 3);
	int random = dis(gen);
	switch (random)
	{
		case 1:
			std::cout << "Generated Object A" << std::endl;
			return new A();
		case 2:
			std::cout << "Generated Object B" << std::endl;
			return new B();
		case 3:
			std::cout << "Generated Object C" << std::endl;
			return new C();
		default:
			std::cout << "Failed to generated any object!" << std::endl;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A is the identified type using a pointer that has been generated" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B is the identified type using a pointer that has been generated" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C is the identified type using a pointer that has been generated" << std::endl;
	else
		std::cout << "Failed to identify the type that has been generated!" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A is the identified type using a refrence that has been generated" << std::endl;
	}
	catch(const std::bad_cast&)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B is the identified type using a refrence that has been generated" << std::endl;
	}
	catch(const std::bad_cast&)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C is the identified type using a refrence that has been generated" << std::endl;
	}
	catch(const std::bad_cast&)
	{
	}
}

int main()
{
	Base *r	= generate();
	identify(r);
	identify(*r);
	delete r;
	r = generate();
	identify(r);
	identify(*r);
	delete r;
	r = generate();
	identify(r);
	identify(*r);
	delete r;
	r = generate();
	identify(r);
	identify(*r);
	delete r;	
	r = generate();
	identify(r);
	identify(*r);
	delete r;
	r = generate();
	identify(r);
	identify(*r);
	delete r;
	return 0;
}