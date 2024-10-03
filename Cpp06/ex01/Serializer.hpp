/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:18 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 13:15:01 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
	std::string name;
	int		number;
	Data	*next;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &cp);
		Serializer &operator=(const Serializer &og);
	
	public:
		static Serializer& getInstance();
		~Serializer();
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif