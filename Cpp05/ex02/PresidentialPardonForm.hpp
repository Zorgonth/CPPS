/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:26 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/20 13:37:29 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const name);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &cp);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &member);

		std::string getTarget() const;
		void execute(Bureaucrat &exec) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &member);

#endif