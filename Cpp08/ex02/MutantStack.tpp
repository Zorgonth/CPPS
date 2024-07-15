/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:13:53 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/28 14:29:04 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
	std::cout << "Default Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cp): std::stack<T>(cp)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = cp;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &og) {
	std::stack<T>::operator=(og);
	std::cout << "MutantStack assignment constructor called" << std::endl;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}