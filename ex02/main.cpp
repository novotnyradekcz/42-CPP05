/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:40:35 by rnovotny          #+#    #+#             */
/*   Updated: 2026/02/27 21:52:18 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Seed random for robotomy
	srand(time(NULL));

	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: RobotomyRequestForm (success case) ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		RobotomyRequestForm robotomy("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robotomy << std::endl;
		
		alice.signForm(robotomy);
		alice.executeForm(robotomy);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Execute without signing ===" << std::endl;
	try
	{
		Bureaucrat lowly("Lowly", 1);
		ShrubberyCreationForm shrub2("office");
		
		std::cout << lowly << std::endl;
		std::cout << shrub2 << std::endl;
		
		lowly.executeForm(shrub2); // Should fail - not signed
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Execute with insufficient grade ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 140);
		ShrubberyCreationForm shrub3("garden");
		
		std::cout << intern << std::endl;
		std::cout << shrub3 << std::endl;
		
		intern.signForm(shrub3);
		intern.executeForm(shrub3); // Should fail - grade too low
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Multiple robotomy attempts ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm rob1("Target1");
		RobotomyRequestForm rob2("Target2");
		RobotomyRequestForm rob3("Target3");
		
		boss.signForm(rob1);
		boss.signForm(rob2);
		boss.signForm(rob3);
		
		boss.executeForm(rob1);
		boss.executeForm(rob2);
		boss.executeForm(rob3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
