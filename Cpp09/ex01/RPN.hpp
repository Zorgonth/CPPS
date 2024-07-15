/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:08:15 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/06 10:44:52 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define DEFAULT "\033[1;39m"

class RPN
{
	private:
		std::string input;
		std::stack<int> nbrs;
	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &og);
		int checkInput(std::string raw);
		void	calculate();
		void	getInput(std::string raw);
};