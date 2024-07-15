/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:26:39 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/09 10:51:22 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void	iter(T *arr, int size, Func f){
	for (int i = 0;i < size;i++)
		f(arr[i]);
}

template <typename T>
void	print(const T &tmp){
	std::cout << tmp;
}

template <typename T>
void	Upper(T &tmp){
	if (tmp >= 97 && tmp <= 122)
		tmp -= 32;
}

#endif