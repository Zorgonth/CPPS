/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:26:06 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/03/20 10:04:26 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>

class Phonebook
{
	public:
		Contact c[8];
		void	startup(int flag);
		void	add(void);
		void	search(void);
		void	display(void);
		void	get_ind(void);
};

#endif