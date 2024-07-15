/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:31 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/20 13:37:54 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm{
	private:
		std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &cp );
		RobotomyRequestForm &operator=(const RobotomyRequestForm &member);

		std::string getTarget() const;
		void execute(Bureaucrat &exec) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &member);

#endif