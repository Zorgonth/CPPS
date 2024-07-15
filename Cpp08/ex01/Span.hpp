/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:57:30 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/28 13:47:10 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <exception>
#include <random>
#include <ctime>
#include <iostream>

class Span
{
	private:
		std::vector<int> vec;
		unsigned int n;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &cp);
		Span &operator=(const Span &og);

	unsigned int shortestSpan();
	unsigned int longestSpan();
	void	addNumber(int add);
	void	removeNumber();
	void	addRange(int start, int end);
	void	Display();
	void	addRandom();
	void	addRandom(int limit);
	class ListAlreadyFull : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class EmptyList : public std::exception
	{
		public:
			virtual const char* what()	const throw();
	};
};
