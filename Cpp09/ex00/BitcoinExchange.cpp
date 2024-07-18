/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:38 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 16:40:58 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc(std::string name)
{
	std::cout << "Default Bitcoin Constructor Called" << std::endl;
	try
	{
		createMap();
		if (map.empty())
			throw InvalidFile();
		getData(name);
   }
	catch(const std::exception &e)
	{
		std::cerr << RED << "ERROR: " << e.what() << DEFAULT <<std::endl;
	}
}

Btc::~Btc()
{
	std::cout << "Default Bitcoin Destructor Called" << std::endl;
}

Btc::Btc(const Btc &cp)
{
	this->map = cp.map;
	std::cout << "Bitcoin Copy Constructor Called" << std::endl;
}

Btc &Btc::operator=(const Btc &og)
{
	if (this != &og)
		this->map = og.map;
	return *this;
}

const char* Btc::InvalidData::what() const throw()
{
	return "Invalid Data! Please Make Sure It's Correct!";
}

const char* Btc::InvalidFile::what() const throw()
{
	return "Invalid File!";
}

void Btc::createMap()
{
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw InvalidFile();
	std::string line;
	double		val;
	std::string date;
	int			pos;

	std::getline(data, line);
	if (line != "date,exchange_rate")
	{
		data.close();
		throw InvalidFile();
	}
	while (std::getline(data, line))
	{
		pos = line.find(",");
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			val = std::strtod(line.substr(pos + 1).c_str(), NULL);
			this->map.insert(std::pair<std::string, double>(date, val));
		}
		if (data.eof())
			break ;
	}
}

void	Btc::getData(std::string name)
{
	std::ifstream data(name);
	if (!data.is_open())
		throw InvalidFile();
	std::string line;
	std::getline(data, line);
	if (line != "date | value")
		throw InvalidFile();
	while (std::getline(data, line))
	{
		if (checkValue(line) == 1)
			continue;
		else
		{
			std::string tmp = line.substr(0, checkValue(line) - 1);
			std::map<std::string, double>::iterator it = this->map.upper_bound(tmp);
			if (it->first > tmp || it != map.begin())
				--it;
			double val = std::strtod(line.substr(checkValue(line) + 1).c_str(), NULL);
			std::cout << GREEN << tmp << " => " << val << " = " << it->second * val << DEFAULT <<std::endl;
		}
		if (data.eof())
			break ;
	}
}

int	Btc::checkValue(std::string line)
{
	int	pos = 0;
	std::string tmp;

	pos = line.find("|");
	if (pos == std::string::npos)
	{
		std::cout << RED << "Error: bad input => " << line << DEFAULT << std::endl;
		return 1;
	}
	tmp = line.substr(0, pos - 1);
	if (tmp.length() != 10 || tmp[4] != '-' || tmp[7] != '-')
	{
		std::cout << RED << "Error: bad input => " << tmp << DEFAULT << std::endl;
		return 1;
	}
	int	year = std::strtod(tmp.substr(0, 4).c_str(), NULL);
	int	month = std::strtod(tmp.substr(5, 2).c_str(), NULL); 
	int	day = std::strtod(tmp.substr(8, 2).c_str(), NULL);

	if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << RED << "Error: bad input => " << tmp << DEFAULT << std::endl;
		return 1;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return 1;
	if ((year % 4 == 0  && year % 100 != 0) || year % 400 == 0)
	{
		if (month == 2 && day > 29)
			return 1;
		else if (month == 2 && day > 28)
			return 1;
	}
	double val = std::strtod(line.substr(pos + 1).c_str(), NULL);
	if (val < 1)
	{
		std::cout << RED << "ERROR: not a positive number" << DEFAULT << std::endl;
		return 1;
	}
	if (val > 1000)
	{
		std::cout << RED << "ERROR: too large a number" << DEFAULT << std::endl;
		return 1;
	}
	return pos;
}
