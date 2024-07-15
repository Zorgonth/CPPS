/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:06 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/30 14:44:36 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define DEFAULT "\033[1;39m"

class Btc
{
	private:
		std::map<std::string, double> map;
	public:
		Btc(std::string name);
		~Btc();
		Btc &operator=(const Btc &og);
		Btc(const Btc &cp);
		void	createMap();
		void	getData(std::string name);
		int	checkValue(std::string line);
		class InvalidFile : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class InvalidData : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};