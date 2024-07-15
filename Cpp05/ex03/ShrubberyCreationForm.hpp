/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:37 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/20 13:38:00 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
	private:
		std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &cp);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &member);

		std::string getTarget() const;
		void execute(Bureaucrat &exec) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &member);

#endif