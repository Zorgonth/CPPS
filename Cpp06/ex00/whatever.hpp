/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:03:29 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/24 13:33:39 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T max(T &a, T &b){
	if (a > b)
		return a;
	return b;
}

template <typename T>
T min(T &a, T &b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

#endif