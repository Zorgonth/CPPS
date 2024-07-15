/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:50:49 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/11 17:16:07 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please enter only the necessary information (Filename, s1, s2)" << std::endl;
		return (1);
	}
	else
	{
		std::string in = std::string(argv[1]); 
		std::ifstream file(in);
		std::string		s1 = std::string(argv[2]);
		std::string		s2 = std::string(argv[3]);
		std::string		line;
		int				pos = 0;
		std::string		new_str;
		
		if (s1.empty())
		{
			std::cout << "Please enter all necessary information (Filename, s1)" << std::endl;
			return (1);
		}
		if (!file)
		{
			std::cout << "Cannot open file : " << in << std::endl;
			return (1);
		}
		std::ofstream file2(in + ".replace");
		if (!file2)
		{
			file.close();
			std::cout << "Cannot create new file : " << in + ".replace" << std::endl;
			return (1);
		}
		if (file.is_open())
		{
			while(std::getline(file, line))
			{
				new_str += line;
				if (file.eof())
					break ;
				new_str += '\n';
			}
			pos = new_str.find(s1);
			while (pos < new_str.length())
			{
				new_str.erase(pos, s1.length());
				new_str.insert(pos, s2);
				pos = new_str.find(s1, pos + s2.length());
			}
			file2 << new_str;
			file2.close();
			file.close();
		}
	}
	return (0);
}