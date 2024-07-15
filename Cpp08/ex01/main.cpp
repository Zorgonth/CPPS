/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:25:48 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 14:15:48 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span t(20);
		t.addNumber(1);
		t.addNumber(5);
		t.removeNumber();
		t.addRange(6, 11);
		t.addRandom();
		std::cout <<"Shortest Span is:"<< t.shortestSpan() << std::endl;
		std::cout <<"Longest Span is"<< t.longestSpan() << std::endl;
		t.Display();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}