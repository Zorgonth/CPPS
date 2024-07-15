/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:31:29 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/23 12:31:16 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &cp);
		virtual ~Animal(void);

		std::string getType(void) const;
		void setType(std::string type);
		Animal &operator=(const Animal &og);
		virtual void makeSound(void) const;
};

#endif