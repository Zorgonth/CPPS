/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:57:21 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 10:46:19 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool  sig;
		const int grad_sign;
		const int grad_exc;
	public:
		Form(void);
		Form(const std::string &name, bool sig, int grad_sig, int grad_ex);
		~Form();
		Form(const Form &cp);
		Form &operator=(const Form &member);
		void	setSig(bool sig);
		bool getSig(void) const;
		std::string getName(void) const;
		int	getGrade_sig(void) const;
		int	getGrade_exc(void) const;
		void	beSigned(Bureaucrat &b);
		class GradeTooHighException: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
		class GradeTooLowException: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
};

std::ostream &operator<<(std::ostream &out, const Form &member);

#endif