/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:40:14 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/06/10 15:23:44 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <utility>
#include <list>

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define DEFAULT "\033[1;39m"

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> list;
	public:
		PmergeMe(std::string input);
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &og);
		int FillInput(std::string input);
		void ListInsertIntoSortedList(std::list<int>& sortedList, int value);
		std::list<int> ListFordJohnsonSort(std::list<int>& inputList);
		std::list<int> ListMergeSortedLists(const std::list<int>& list1, const std::list<int>& list2);
		std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2);
		void insertIntoSortedVector(std::vector<int>& sortedVector, int value);
		std::vector<int> VecFordJohnsonSort(std::vector<int>& inputVector);
};

std::string MergeArgs(char **argv);