/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:57:23 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 10:22:52 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("AForm"), sig(false), grad_sign(150), grad_exc(150)
{
	std::cout << "Default AForm Constructor Called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exc() < 1)
		throw GradeTooLowException();
	if (this->getGrade_sig() > 150 || this->getGrade_exc() > 150)
		throw GradeTooHighException();
}

AForm::AForm(const std::string &name, bool sig, int grad_sig, int grad_ex) : name(name), sig(sig), grad_sign(grad_sig), grad_exc(grad_ex)
{
	std::cout << "AForm Constructor Called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exc() < 1)
		throw GradeTooLowException();
	if (this->getGrade_sig() > 150 || this->getGrade_exc() > 150)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	std::cout <<  "AForm: " << this->getName() << " Destructor Called" << std::endl;
	delete this;
}

AForm::AForm(const AForm &cp) : name(cp.getName()), sig(cp.getSig()), grad_sign(cp.getGrade_sig()), grad_exc(cp.getGrade_exc())
{
	std::cout << "AForm Copy Constructor Called" << std::endl;	
}

AForm &AForm::operator=(const AForm &member)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &member)
	{
		this->setSig(member.getSig());
	}
	return *this;
}

const	char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const	char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

const char* AForm::AFormNotSigned::what() const throw()
{
	return "Form Is Not Signed!";
}

void AForm::execute(Bureaucrat &exec)const
{
	(void)exec;
}

void AForm::setSig(bool sig)
{
	this->sig = sig;
}

bool AForm::getSig(void) const
{
	return this->sig;
}
std::string AForm::getName(void) const
{
	return this->name;
}

int AForm::getGrade_exc(void) const
{
	return this->grad_exc;
}

int AForm::getGrade_sig(void) const
{
	return this->grad_sign;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGrade_sig())
	{
		if (!this->getSig())
		{
			this->setSig(true);
			std::cout << this->name << " Is Signed Successfully!" << std::endl;
		}
		else
			std::cout << "This AForm Has Already Been Signed!" << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &member) {
	out << member.getName() << ", Required signing grade: " << member.getGrade_sig() << " Required executing grade: " << member.getGrade_exc() << "." << std::endl;
	return (out);
}