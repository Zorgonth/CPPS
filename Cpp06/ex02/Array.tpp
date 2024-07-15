/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:34:31 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/27 14:35:24 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : array(nullptr), size(0)
{
	std::cout << "Array Default Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->size = size;
	std::cout << "Array Constructor Called" << std::endl;
	this->array = new T[this->size]();
}
template <typename T>
Array<T>::~Array(void)
{
	delete []array;
	std::cout << "Array Destructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &og): size(og.size)
{
	std::cout << "Array Copy Constructor Called" << std::endl;
	array = new T[size];
	for (unsigned int i = 0; i < this->size;i++)
		this->array[i] = og.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &member)
{
	std::cout << "Array Copy Assignment Calledd" << std::endl;
	if (this != &member)
	{
		delete []array;
		this->size = member.size;
		this->array = new T[this->size];
		for (unsigned int i = 0;i < this->size;i++)
			this->array[i] = member.array[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::getSize(void) const
{
	return this->size;
}

template <typename T>
T &Array<T>::operator[](unsigned int ind)
{
	if (this->size <= ind)
		throw InvalidIndex();
	else
		return this->array[ind];
}

template <typename T>
const char* Array<T>::InvalidIndex::what() const throw()
{
	return "Index Out Of Bounds!";
}