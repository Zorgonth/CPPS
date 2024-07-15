/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:28 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 11:03:39 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target("Default") 
{
	std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const name) : AForm("RobotomyRequestForm", false, 72, 45), target(name)
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
} 

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cp) : AForm(cp), target(cp.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &member)
{
	std::cout << "RobotomyRequestForm Assignment Operator Called" << std::endl;
	if (this != &member)
	{
		this->setSig(member.getSig());
		this->target = member.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat &exec) const
{
	if (this->getSig() && exec.getGrade() <= this->getGrade_exc())
	{
		std::cout << "Some Drilling Noises..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << this->target << "'s Robotomy has failed!" << std::endl;
		std::cout << exec.getName() << "executed " << this->target << std::endl;
	}
	else
	{
		if (!this->getSig())
			throw AFormNotSigned();
		else
			throw GradeTooHighException();
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &member)
{
	out << member.getName() << ", Target: " << member.getTarget();
	out << static_cast<const AForm&>(member);
	return (out);
}