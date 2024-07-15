/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:22 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/20 13:40:34 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 25), target("Default") 
{
	std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const name) : AForm("PresidentialPardonForm", false, 25, 25), target(name)
{
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
} 

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cp) : AForm(cp), target(cp.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &member)
{
	std::cout << "PresidentialPardonForm Assignment Operator Called" << std::endl;
	if (this != &member)
	{
		this->setSig(member.getSig());
		this->target = member.getTarget();
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat &exec) const
{
	if (this->getSig() && exec.getGrade() <= this->getGrade_exc())
	{
		std::cout << this->target << " Has been Pardoned By Zaphod Beelbrox" << std::endl;
		std::cout << exec.getName() << " executed " << this->target << std::endl;
	}
	else
	{
		if (!this->getSig())
			throw AFormNotSigned();
		else
			throw GradeTooHighException();
	}
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &member)
{
	out << member.getName() << ", Target: " << member.getTarget();
	out << static_cast<const AForm&>(member);
	return (out);
}