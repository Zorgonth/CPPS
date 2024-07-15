/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/08 10:25:26 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
    {
        Bureaucrat b1("General", 10);
        std::cout << b1 << std::flush;
        Intern i;
        AForm *f = i.makeform("PresidentialPardonForm", "BIG");
        b1.signForm(*f);
        b1.executeform(*f);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b2("Soldier", 70);
        std::cout << b2 << std::flush;
        Intern i;
        AForm *f = i.makeform("RobotomyRequestForm", "Random");
        b2.signForm(*f);
        b2.setGrade(40);
        b2.executeform(*f);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b3("Soldier", 120);
        std::cout << b3 << std::flush;
        Intern i;
        AForm *f3 = i.makeform("ShrubberyCreationForm", "TREEE");
        b3.signForm(*f3);
        b3.executeform(*f3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return 0;
}