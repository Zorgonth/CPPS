/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:33:15 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 10:57:26 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

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
		void	signForm(AForm &f);
		void	executeform(AForm const &f);
		
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