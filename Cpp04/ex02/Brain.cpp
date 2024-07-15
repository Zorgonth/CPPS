/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:58:16 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/04/26 14:12:15 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain Constructor Called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Default Brain Deconstructor Called" << std::endl;
}

Brain::Brain(Brain &cp)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	if (this != &cp)
		*this = cp;
}

Brain &Brain::operator=(Brain &og) {
	std::cout << "Brain Assignment Operator Called" << std::endl;
	if (this != &og)
	{
		for (int i = 0; i < 100; i++)
			this->SetIdea(i, og.GetIdea(i));
	}
	return *this;
}

std::string Brain::GetIdea(int ind)
{
	if (ind < 0 || ind >= 100)
	{
		std::cout << "Index Out Of Bounds" << std::endl;
		return (NULL);
	}
	return (this->ideas[ind]);
}

void Brain::SetIdea(int ind, std::string idea)
{
	if (ind < 0 || ind >= 100)
		std::cout << "Index Out Of Bounds" << std::endl;
	else
		this->ideas[ind] = idea;
}
