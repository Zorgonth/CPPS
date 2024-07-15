/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/16 15:25:04 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
    {
        Bureaucrat b1("General", 1);
        std::cout << b1 << std::flush;
        Form f1("Promotion", false, 1, 1);
        std::cout << f1 << std::flush;
        f1.beSigned(b1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b2("Soldier", 120);
        std::cout << b2 << std::flush;
        Form f1("Promotion", false, 1, 1);
        std::cout << f1 << std::flush;
        f1.beSigned(b2);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b2("Soldier", 120);
        std::cout << b2 << std::flush;
        b2.increment();
        Form f1("Promotion", false, 119, 119);
        std::cout << f1 << std::flush;
        f1.beSigned(b2);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return 0;
}