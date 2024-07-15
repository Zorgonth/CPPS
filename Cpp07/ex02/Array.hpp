/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:28:00 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/27 14:17:53 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T	*array;
		unsigned int	size;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array &cp);
		Array &operator=(const Array &member);
		unsigned int getSize(void) const;
		T &operator[](unsigned int ind);

		class InvalidIndex : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};
#include "Array.tpp"

#endif