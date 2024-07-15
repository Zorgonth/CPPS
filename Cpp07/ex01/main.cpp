/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:31:55 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 10:52:26 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
//make more tests!
int main()
{
	std::string str = "hello world";

	iter(&str[0], str.length(), print<char>);
	std::cout << std::endl;
	iter(&str[0], str.length(), Upper<char>);
	iter(&str[0], str.length(), print<char>);
	std::cout << std::endl;
	return 0;
}