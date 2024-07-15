/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:17:18 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 13:52:44 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class NonExistingValue : public std::exception
{
	public:
		virtual const char* what() const throw();
};

template <typename T>
void	easyfind(T &container, int find)
{
	typename T::iterator i;

	i = std::find(container.begin(), container.end(), find);
	if (i != container.end())
		std::cout << "The Value Has Been Found: " << *i << std::endl;
	else
		throw NonExistingValue();
}