/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/07/05 11:09:25 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
    {
        Bureaucrat b1("General", 1);
        std::cout << b1 << std::flush;
        PresidentialPardonForm f1("Criminal");
        b1.signForm(f1);
        b1.executeform(f1);
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
        RobotomyRequestForm f2("Random");
        b2.signForm(f2);
        b2.setGrade(40);
        b2.executeform(f2);
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
        ShrubberyCreationForm f3("TREEEEE");
        b3.signForm(f3);
        b3.executeform(f3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return 0;
}