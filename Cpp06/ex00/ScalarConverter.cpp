/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:19 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 10:38:34 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor Called" << std::endl;
}
ScalarConverter& ScalarConverter::getInstance() {
    static ScalarConverter instance;
    return instance;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &cp)
{
	std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &member)
{
	return *this;
}

void	ScalarConverter::Error(std::string str)
{
	std::cerr << "Wrong input: " <<  str << std::endl;
}

void	ScalarConverter::HandleInf()
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: inff" << std::endl;
	std::cout << "Double: inf" << std::endl;
}

void	ScalarConverter::HandleNinf()
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: -inff" << std::endl;
	std::cout << "Double: -inf" << std::endl;
}

void	ScalarConverter::HandleNan()
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: nanf" << std::endl;
	std::cout << "Double: nan" << std::endl;
}

int	ScalarConverter::Checker(std::string str)
{
	int 	fflag = 0;
	int	flag = 0;
	if (str.empty())
		return Error("empty string"), 0;
	if (str == "inf" || str == "+inf")
		return HandleInf(), 0;
	if (str == "-inf")
		return HandleNinf(), 0;
	if (str == "inff" || str == "+inff")
		return HandleInf(), 0;
	if (str == "-inff")
		return HandleNinf(), 0;
	if (str == "nan")
		return HandleNan(), 0;
	if (str == "nanf")
		return HandleNan(), 0;
	if (str.length() == 1)
	{
		if (!std::isdigit(str[0]))
			return 1;
	}
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == '-')
		{
			if (i != 0)
				return Error(str), 0;
			i++;
		}
		if (!std::isdigit(str[i]))
		{
			if (str[i] != '.' && str[i] != 'f')
				return Error(str), 0;
			else
			{
				if (str[i] == '.')
				{
					if (i == str.length() - 1 || i == 0)	
						return Error(str), 0;
					else
						flag++;
				}
				if (str[i] == 'f')
				{
					if (i == str.length() - 1 && str[i - 1] != '.')	
						fflag++;
					else
						return Error(str), 0;
				}
			}	
			if (flag > 1 || fflag > 1)
				return Error(str), 0;
		}
	}
	return 1;
}

void	ScalarConverter::HandleChar(std::string str)
{
	char c;
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		c = static_cast<char>((int)str[0]);
		std::cout << "Char: " << c << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		if (d < 32 || d > 127)
		{
			std::cout << "Char: Non Displayable" << std::endl;
			return ;
		}
		c = static_cast<char>(d);
		std::cout << "Char: " << c << std::endl;		
		return ;
	}
	if (str.find("f") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		if (d < 32 || d > 127)
		{
			std::cout << "Char: Non Displayable" << std::endl;
			return ;
		}
		c = static_cast<char>(d);
		std::cout << "Char: " << c << std::endl;		
		return ;
	}
	int i = std::atoi(str.c_str());
	if (i < 32 || i > 127)
	{
		std::cout << "Char: Non Displayable" << std::endl;
		return ;
	}
	c = static_cast<char>(i);
	std::cout << "Char: " << c << std::endl;
	return ;
}

void	ScalarConverter::HandleInt(std::string str)
{
	int i;
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		i = static_cast<int>(str[0]);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		i = static_cast<int>(d);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		i = static_cast<int>(d);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	i = std::atoi(str.c_str());
	std::cout << "Int: " << i << std::endl;
}

void	ScalarConverter::HandleFloat(std::string str)
{
	float f;
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		f = static_cast<float>(str[0]);
		std::cout << std::fixed << std::setprecision(1) << "Float: " << f << "f" << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		f = static_cast<float>(d);
		std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos)
	{
		double d = std::strtod(str.c_str(), NULL);
		f = static_cast<float>(d);
		std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
		return ;
	}	
	int i = std::atoi(str.c_str());
	f = static_cast<float>(i);
	std::cout << std::fixed << std::setprecision(1) << "Float: " << f << "f" << std::endl;
}

void	ScalarConverter::HandleDouble(std::string str)
{
	double d;
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		d = static_cast<double>(str[0]);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos)
	{
		d = std::strtod(str.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos)
	{
		d = std::strtod(str.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}	
	int i = std::atoi(str.c_str());
	d = static_cast<double>(i);
	std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;	
}

void ScalarConverter::convert(std::string str)
{
	if (!Checker(str))
		return ;
	HandleChar(str); 
	HandleInt(str);
	HandleFloat(str);
	HandleDouble(str);
}