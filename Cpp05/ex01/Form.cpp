/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:57:23 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 10:46:03 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Form"), sig(false), grad_sign(150), grad_exc(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exc() < 1)
		throw GradeTooLowException();
	if (this->getGrade_sig() > 150 || this->getGrade_exc() > 150)
		throw GradeTooHighException();
}

Form::Form(const std::string &name, bool sig, int grad_sig, int grad_ex) : name(name), sig(sig), grad_sign(grad_sig), grad_exc(grad_ex)
{
	std::cout << "Form Constructor Called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exc() < 1)
		throw GradeTooLowException();
	if (this->getGrade_sig() > 150 || this->getGrade_exc() > 150)
		throw GradeTooHighException();
}

Form::~Form()
{
	std::cout <<  "Form: " << this->getName() << " Destructor Called" << std::endl;
}

Form::Form(const Form &cp) : name(cp.getName()), sig(cp.getSig()), grad_sign(cp.getGrade_sig()), grad_exc(cp.getGrade_exc())
{
	std::cout << "Form Copy Constructor Called" << std::endl;	
}

Form &Form::operator=(const Form &member)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &member)
	{
		this->setSig(member.getSig());
	}
	return *this;
}

const	char* Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const	char* Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

void Form::setSig(bool sig)
{
	this->sig = sig;
}

bool Form::getSig(void) const
{
	return this->sig;
}
std::string Form::getName(void) const
{
	return this->name;
}

int Form::getGrade_exc(void) const
{
	return this->grad_exc;
}

int Form::getGrade_sig(void) const
{
	return this->grad_sign;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGrade_sig())
	{
		if (!this->getSig())
		{
			this->setSig(true);
			std::cout << this->name << " Is Signed Successfully!" << std::endl;
		}
		else
			std::cout << "This Form Has Already Been Signed!" << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &member) {
	out << member.getName() << ", Required signing grade: " << member.getGrade_sig() << " Required executing grade: " << member.getGrade_exc() << "." << std::endl;
	return (out);
}