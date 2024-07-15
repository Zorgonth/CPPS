/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:48:57 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/10 10:06:50 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string MergeArgs(char **argv)
{
	std::string res;
	for (int i = 1;argv[i];i++)
	{
		res = res + argv[i];
		res = res + ' ';
	}
	std::string tmp;
	int i = 0;
	int j = 0;
	while (i < res.length())
	{
		if (res[i] != ' ' && res[i] != '+' && !isdigit(res[i]))
		{
			tmp.clear();
			res.clear();
			return tmp;
		}		
		if (res[i] == '+')
		{
			if (i == res.length() - 1)
			{
				tmp.clear();
				res.clear();
				return tmp;
			}
			else if (res[i + 1] == ' ')
			{
				tmp.clear();
				res.clear();
				return tmp;
			}
			else
				tmp = tmp + res[i];
		}
		if (isdigit(res[i]))
		{
			tmp = tmp + res[i];
		}
		if (res[i] == ' ')
		{
			while (res[i] == ' ')
				i++;
			tmp = tmp + ' ';
			i--;
		}
		i++;
	}
	tmp.erase(tmp.length() - 1);
	return tmp;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cerr << RED << "Wrong number Of Arguments!, Please input positive numbers!" << DEFAULT << std::endl;
	else
	{
		std::string input;
		input = MergeArgs(argv);
		if (input.empty())
		{
			std::cerr << RED << "Wrong Input!" << DEFAULT << std::endl;
			return 1;
		}
		PmergeMe pmergeme(input);
	}
	return 0;
}