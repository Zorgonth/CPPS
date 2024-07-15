/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:37:53 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 12:12:10 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("Nobody")
{
	std::cout << "Default Constructor Called" << std::endl;
	this->grade = 2;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :name(name)
{
	std::cout << "Bureaucrat Constructor Called" << std::endl;
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp): name(cp.getName()), grade(cp.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return this->name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	else
		this->grade = grade;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &member) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &member) {
		this->setGrade(member.getGrade());
	}
	return *this;
}

void	Bureaucrat::increment(void)
{
	this->setGrade((this->getGrade()) - 1);
}

void	Bureaucrat::decrement(void)
{
	this->setGrade((this->getGrade()) + 1);
}

const	char* Bureaucrat::GradeTooHigh::what() const throw()
{
	return "Grade Too High!";
}

const	char* Bureaucrat::GradeTooLow::what() const throw()
{
	return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &member) {
	out << member.getName() << ", bureaucrat grade " << member.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat: " << this->getName() << " Deconstructor called" << std::endl;
}