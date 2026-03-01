/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:40:35 by rnovotny          #+#    #+#             */
/*   Updated: 2026/02/28 21:35:12 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Seed random for robotomy
	srand(time(NULL));

	std::cout << "=== Test 1: Intern creates ShrubberyCreationForm ===" << std::endl;
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "home");
		
		if (form)
		{
			Bureaucrat bob("Bob", 137);
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Intern creates RobotomyRequestForm ===" << std::endl;
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "Bender");
		
		if (form)
		{
			Bureaucrat alice("Alice", 1);
			std::cout << *form << std::endl;
			alice.signForm(*form);
			alice.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Intern creates PresidentialPardonForm ===" << std::endl;
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Arthur Dent");
		
		if (form)
		{
			Bureaucrat president("President", 1);
			std::cout << *form << std::endl;
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Intern tries to create invalid form ===" << std::endl;
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("invalid form", "target");
		
		if (!form)
		{
			std::cout << "Form creation failed as expected" << std::endl;
		}
		else
		{
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Multiple forms created by one intern ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm *form1 = intern.makeForm("shrubbery creation", "garden");
		AForm *form2 = intern.makeForm("robotomy request", "Target1");
		AForm *form3 = intern.makeForm("presidential pardon", "Criminal");
		
		if (form1)
		{
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		
		if (form2)
		{
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		
		if (form3)
		{
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
