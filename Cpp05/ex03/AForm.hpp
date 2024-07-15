/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:57:21 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 13:41:12 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool  sig;
		const int grad_sign;
		const int grad_exc;
		AForm(void);
		AForm(const std::string &name, bool sig, int grad_sig, int grad_ex);
	public:
		virtual ~AForm();
		AForm(const AForm &cp);
		AForm &operator=(const AForm &member);
		void	setSig(bool sig);
		bool getSig(void) const;
		std::string getName(void) const;
		int	getGrade_sig(void) const;
		int	getGrade_exc(void) const;
		void	beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat &exec)const = 0;
		class GradeTooHighException: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
		class GradeTooLowException: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
		class AFormNotSigned: public std::exception{
			virtual const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &member);

#endif