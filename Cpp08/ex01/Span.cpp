/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:19 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/28 13:47:08 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->n = 0;
	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int n)
{
	this->n = n;
	std::cout << "Span Constructor Called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor Called" << std::endl;
}

Span::Span(const Span &cp)
{
	this->n = cp.n;
	this->vec = cp.vec;
	std::cout << "Span Copy Constructor Called" << std::endl;
}

Span &Span::operator=(const Span &og)
{
	if (this != &og)
	{
		this->n = og.n;
		this->vec = og.vec;
	}
	return *this;
}

const char* Span::EmptyList::what() const throw()
{
	return "The List is Empty, Please Add Numbers/Add to the Span!";
}

const char* Span::ListAlreadyFull::what() const throw()
{
	return "Cannot Add To The List!";
}

void Span::addNumber(int add)
{
	if (this->n > vec.size())	
		vec.push_back(add);
	else
		throw ListAlreadyFull();
}

void	Span::removeNumber()
{
	if (this->n >= 1 && vec.size())
		vec.pop_back();
	else
		throw EmptyList();
}

unsigned int Span::shortestSpan()
{
	unsigned int min;
	if (this->n >= 2 &&( vec.size() >= 2))
	{
		unsigned int b;
		unsigned int res;
		min = std::abs(vec[0] - vec[1]);
		for (unsigned int j = 0;j < vec.size();j++)
		{
			b = j;
			while (++b < vec.size())
			{
				res = std::abs(vec[j] - vec[b]);
				if (res < min)
					min = res;
			}
		}
	}
	else
		throw EmptyList();
	return min;
}

unsigned int Span::longestSpan()
{
	unsigned int max;
	if (this->n >= 2 && (vec.size() >= 2))
	{
		unsigned int b;
		unsigned int res;
		max = std::abs(vec[0] - vec[1]);
		for (unsigned int j = 0;j < vec.size();j++)
		{
			b = j;
			while (++b < vec.size())
			{
				res = std::abs(vec[j] - vec[b]);
				if (res > max)
					max = res;
			}
		}
	}
	else
		throw EmptyList();
	return max;
}

void	Span::addRange(int start, int end)
{
	unsigned int range = std::abs(end - start);
	unsigned int available = n - vec.size();
	if (available >= range)
	{
		int tmp = std::min(end, start);
		while (tmp <= std::max(end, start))
		{
			addNumber(tmp);
			tmp++;
		}
	}
	else
		throw ListAlreadyFull();
}

void	Span::Display()
{
	if (this->n >= 1 && vec.size())
	{
		for (unsigned int i = 0; i < vec.size();i++)
			std::cout << vec[i] << std::endl;
	}
	else
		throw EmptyList();
}

void	Span::addRandom()
{
	if (this->n > vec.size())
	{
		unsigned int	size = n;
		std::random_device rd;
   	std::mt19937 gen(rd());
   	std::uniform_int_distribution<> dis(0, 100000);
		while (vec.size() < size)
		{
			unsigned int random = dis(gen);
			addNumber(random);
		}
	}
	else
		throw ListAlreadyFull();
}

void	Span::addRandom(int limit)
{
	if (this->n > vec.size())
	{
		unsigned int	size = n;
		std::random_device rd;
   	std::mt19937 gen(rd());
   	std::uniform_int_distribution<> dis(0, limit);
		while (vec.size() < size)
		{
			unsigned int random = dis(gen);
			addNumber(random);
		}
	}
	else
		throw ListAlreadyFull();
}