/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:03:21 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/03/20 12:20:24 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>

class Contact 
{
	private:
		std::string first_n;
		std::string last_n;
		std::string number;
		std::string nick_n;
		std::string secret;
		int	checker(std::string str);
		int	ind;
		std::string	in(void);
		std::string in_n(void);

	public:
		void	set(int i);
		void	init(void);
		void	view(int ind);
		void	display_all();
};

#endif