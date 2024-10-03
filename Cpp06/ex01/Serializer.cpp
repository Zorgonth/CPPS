/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:16 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 13:15:30 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Constructor Called" << std::endl;
}

Serializer& Serializer::getInstance() {
    static Serializer instance;
    return instance;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor Called" << std::endl;
}

Serializer::Serializer(const Serializer &cp)
{
	std::cout << "Serializer Copy Constructor Called" << std::endl;
	*this = cp;
}

Serializer	&Serializer::operator=(const Serializer &og)
{
	std::cout << "Serializer Copy Assignment Called" << std::endl;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}