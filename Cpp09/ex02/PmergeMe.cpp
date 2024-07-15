/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:46:17 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/10 10:07:53 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static long long GetCurrentTimeMicros() {
    clock_t time = clock();
    return (time * 1000000) / CLOCKS_PER_SEC;
}

PmergeMe::PmergeMe(std::string input)
{
	FillInput(input);
	long long startTime = GetCurrentTimeMicros();

   long long endTime = GetCurrentTimeMicros();
   long long TimeForLists = endTime - startTime;
    std::cout << "Before :";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
   }
	std::list<int> sortedNumbers = ListFordJohnsonSort(this->list);
   std::cout << std::endl;
	startTime = GetCurrentTimeMicros();
	std::vector<int> sorted = VecFordJohnsonSort(this->vec);
   endTime = GetCurrentTimeMicros();
   long long elapsedTime = endTime - startTime;
    std::cout << "After :";
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << GREEN << "Elapsed time For Vectors: " << elapsedTime << " microseconds" << DEFAULT <<std::endl;
    std::cout << GREEN << "Elapsed time For Lists: " << TimeForLists << " microseconds" << DEFAULT <<std::endl;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cp)
{
	this->vec = cp.vec;
	this->list = cp.list;
	std::cout << "PmergeMe Copy Constructor Called" << std::endl;
}

int PmergeMe::FillInput(std::string input)
{
	int j = 0;
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == ' ')
		{
			std::string tmp = input.substr(j, i).c_str();
			double val = std::strtod(tmp.c_str(), NULL);
			this->vec.push_back(val);
			this->list.push_back(val);
			j = i + 1;
		}
	}
	std::string tmp = input.substr(j, input.length()).c_str();
	double val = std::strtod(tmp.c_str(), NULL);
	this->vec.push_back(val);
	this->list.push_back(val);
	return 0;
}

std::list<int> PmergeMe::ListMergeSortedLists(const std::list<int>& list1, const std::list<int>& list2) {
   std::list<int> result;
   std::list<int>::const_iterator it1 = list1.begin();
   std::list<int>::const_iterator it2 = list2.begin();
   
   while (it1 != list1.end() && it2 != list2.end()) {
       if (*it1 <= *it2) {
           result.push_back(*it1++);
       } else {
           result.push_back(*it2++);
       }
   }
   result.insert(result.end(), it1, list1.end());
   result.insert(result.end(), it2, list2.end());
   return result;
}

void PmergeMe::ListInsertIntoSortedList(std::list<int>& sortedList, int value) {
   std::list<int>::iterator it;
   for (it = sortedList.begin(); it != sortedList.end(); ++it) {
       if (value < *it) {
           sortedList.insert(it, value);
           return;
       }
   }
   sortedList.push_back(value);
}

std::list<int> PmergeMe::ListFordJohnsonSort(std::list<int>& inputList) {
   if (inputList.size() <= 1) {
       return inputList;
   }
   std::list<int>::iterator middle = inputList.begin();
   std::advance(middle, inputList.size() / 2);
   std::list<int> firstHalf(inputList.begin(), middle);
   std::list<int> secondHalf(middle, inputList.end());
   firstHalf = ListFordJohnsonSort(firstHalf);
   secondHalf = ListFordJohnsonSort(secondHalf);
   std::list<int> sortedList = ListMergeSortedLists(firstHalf, secondHalf);
   return sortedList;
}

std::vector<int> PmergeMe::mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> result;
    std::vector<int>::const_iterator it1 = vec1.begin();
    std::vector<int>::const_iterator it2 = vec2.begin();
    
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 <= *it2) {
            result.push_back(*it1++);
        } else {
            result.push_back(*it2++);
        }
    }
    result.insert(result.end(), it1, vec1.end());
    result.insert(result.end(), it2, vec2.end());
    
    return result;
}

void PmergeMe::insertIntoSortedVector(std::vector<int>& sortedVector, int value) {
    std::vector<int>::iterator it;
    for (it = sortedVector.begin(); it != sortedVector.end(); ++it) {
        if (value < *it) {
            sortedVector.insert(it, value);
            return;
        }
    }
    sortedVector.push_back(value);
}

std::vector<int> PmergeMe::VecFordJohnsonSort(std::vector<int>& inputVector) {
    if (inputVector.size() <= 1) {
        return inputVector;
    }
    
    std::vector<int>::iterator middle = inputVector.begin();
    std::advance(middle, inputVector.size() / 2);
    std::vector<int> firstHalf(inputVector.begin(), middle);
    std::vector<int> secondHalf(middle, inputVector.end());
    firstHalf = VecFordJohnsonSort(firstHalf);
    secondHalf = VecFordJohnsonSort(secondHalf);
    std::vector<int> sortedVector = mergeSortedVectors(firstHalf, secondHalf);
    return sortedVector;
}