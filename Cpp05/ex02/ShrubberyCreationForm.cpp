/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:35 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/21 12:49:26 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("Default") 
{
	std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name) : AForm("ShrubberyCreationForm", false, 145, 137), target(name)
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
} 

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cp) : AForm(cp), target(cp.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &member)
{
	std::cout << "ShrubberyCreationForm Assignment Operator Called" << std::endl;
	if (this != &member)
	{
		this->setSig(member.getSig());
		this->target = member.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat &exec) const
{
	if (this->getSig() && exec.getGrade() <= this->getGrade_exc())
	{
		std::ofstream out ("Shrubbery");
		if (out.is_open())
		{
			out << "       @@@@@" << std::endl;
			out << "     @@@@&&&&@@" << std::endl;
			out << "   @@&&&&&&&&&@@@" << std::endl;
			out << "  @&&&&&&&&&&&&&&@" << std::endl;
			out << "@@@&&&&&&&&&&&&&&@@@" << std::endl;
			out << "  @&&&&&&&&&&&&&&@" << std::endl;
			out << "    &&&&&&&&&&&&" << std::endl;
			out << "      &&&&&&&&" << std::endl;
			out << "        &&&&" << std::endl;
			out << "         ||" << std::endl;
			out << "         ||" << std::endl;
			out << "         ||" << std::endl;
        out.close();
		}
		else
			std::cerr << "Shrubbery has failed to open!" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &member)
{
	out << member.getName() << ", Target: " << member.getTarget();
	out << static_cast<const AForm&>(member);
	return (out);
}