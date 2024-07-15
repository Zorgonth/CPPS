/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:43:26 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 11:54:25 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(Intern &cp)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &member)
{
	std::cout << "Intern assignment Operator Called" << std::endl;
	return *this;
}

static AForm *makePresedential(std::string target)
{
	PresidentialPardonForm *p = new PresidentialPardonForm(target);
	return p;
}

static AForm *makeRobotomy(std::string target)
{
	RobotomyRequestForm *p = new RobotomyRequestForm(target);
	return p;
}

static AForm *makeShrubbery(std::string target)
{
	ShrubberyCreationForm *p = new ShrubberyCreationForm(target);
	return p;
}

const	char* Intern::FormNotFound::what() const throw()
{
	return "FormNotFound";
}

AForm	*Intern::makeform(std::string name, std::string target)
{
	if (name.empty() || target.empty())
	{
		std::cout << "Please Fill Out Both needed arguments!" << std::endl;
		return NULL;
	}
	std::string comp[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	AForm *(*arr[])(std::string tar) = {&makePresedential, &makeShrubbery, &makeRobotomy};
	for (int i = 0;i < 3;i++)
	{
		if (comp[i] == name)
		{
			std::cout << "Intern Creates " << name << std::endl;
			return (arr[i](target));
		}
	}
	throw FormNotFound();
	return NULL;
}

