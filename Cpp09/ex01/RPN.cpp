/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/06 16:20:39 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
{
	std::cout << "RPN Constructor Called" << std::endl;
	if (checkInput(input) == 1)
	{
		std::cout << RED << "Error" << DEFAULT << std::endl;
		return ;
	}
	getInput(input);
	calculate();
}

void RPN::getInput(std::string raw)
{
	for (int i = 0;i < raw.length();i++)
	{
		char c = raw[i];
		if (isdigit(c))
			input.push_back(c);
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			input.push_back(c);
	}
}

RPN::~RPN()
{
	std::cout << "RPN Destructor Called" << std::endl;
}

RPN::RPN(const RPN &cp)
{
	this->input = cp.input;
	this->nbrs = cp.nbrs;
	std::cout << "RPN Copy Constructor Called" << std::endl;
}

RPN &RPN::operator=(const RPN &og)
{
	if (this != &og)
	{
		this->input = og.input;	
		this->nbrs = og.nbrs;
	}
	return *this;
}

int	RPN::checkInput(std::string raw)
{
	if (raw.empty())
		return 1;
	for (int i = 0;i < raw.length();i++)
	{
		if (!isdigit(raw[i]))
		{
			if (raw[i] != '+' && raw[i] != '*' && raw[i] != '-' && raw[i] != '/' && raw[i] != ' ')
				return 1;
		}
	}
	int nbr = 0;
	int op = 0;
	for (int i = 0; i < raw.length();i++)
	{
		if (isdigit(raw[i]))
			nbr++;
		if (raw[i] == '+' || raw[i] == '*' || raw[i] == '-' || raw[i] == '/')
			op++;
	}
	if (nbr != op + 1)
		return 1;
	return 0;
}

void	RPN::calculate()
{
	int	a, b;
	for (int i = 0;i < input.length();i++)
	{
		if (isdigit(input[i]))
			nbrs.push((int)input[i] - '0');
		else
		{ 
				if (nbrs.empty()) {
					std::cout << RED << "Error" << DEFAULT << std::endl;
					return ;
				}
				a = nbrs.top();
				nbrs.pop();
				if (nbrs.empty()) {
					std::cout << RED << "Error" << DEFAULT << std::endl;
					return ;
				}
				b = nbrs.top();
				nbrs.pop();
				switch(input[i])
				{
					case '+':
						a = a + b;
						break ;
					case '-':
						a = b - a;
						break ;
					case '/':
						a = b / a;
						break ;
					case '*':
						a = a * b;
						break ;
				}
			nbrs.push(a);
		}
	}
	std::cout << GREEN << "RESULT IS: " << nbrs.top() << DEFAULT << std::endl;
}