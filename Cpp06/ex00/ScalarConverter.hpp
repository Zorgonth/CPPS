/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:26:25 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 10:38:16 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &cp);
		ScalarConverter &operator=(const ScalarConverter &member);
	public:
		static ScalarConverter& getInstance();
		~ScalarConverter();
		void	convert(std::string str);
		void	HandleDouble(std::string str);
		void	HandleFloat(std::string str);
		void	HandleInt(std::string str);
		void	HandleChar(std::string str);
		int	Checker(std::string str);
		void	Error(std::string str);
		void	HandleInf();
		void	HandleNinf();
		void	HandleNan();
};

#endif