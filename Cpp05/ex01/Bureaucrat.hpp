/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:33:15 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/14 11:11:14 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &cp);
		Bureaucrat &operator=(const Bureaucrat &member);
		void setGrade(int grade);
		int getGrade(void) const;
		const std::string getName(void) const;
		void increment(void);
		void decrement(void);
		void	signForm(Form &f);
		class GradeTooHigh: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
		class GradeTooLow: public std::exception{
			public:
			virtual const char	*what(void) const throw();	
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &member);

#endif