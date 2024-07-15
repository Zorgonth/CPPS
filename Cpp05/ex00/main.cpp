/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:32 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/05/07 16:57:00 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
        Bureaucrat bureaucrat("Bob", 2);
        std::cout << bureaucrat;
        std::cout << "Name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat bureaucrat1("Lad", 1);
        bureaucrat1.increment();
        std::cout << bureaucrat1;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try {
        Bureaucrat bureaucrat2("Ash", 150);
        bureaucrat2.decrement();
        std::cout << bureaucrat2;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat bureaucrat1("Lad", 10);
        std::cout << bureaucrat1;
        bureaucrat1.increment();
        std::cout << bureaucrat1;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try {
        Bureaucrat bureaucrat2("Ash", 140);
        std::cout << bureaucrat2;
        bureaucrat2.decrement();
        std::cout << bureaucrat2;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	 return 0;
}