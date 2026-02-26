/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:40:35 by rnovotny          #+#    #+#             */
/*   Updated: 2026/02/26 16:49:08 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Test valid bureaucrat creation
	try
	{
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test grade increment and decrement
	try
	{
		Bureaucrat b3("Charlie", 2);
		std::cout << b3 << std::endl;
		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;
		b3.decrementGrade();
		std::cout << "After decrement: " << b3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test form creation and signing
	try
	{
		Bureaucrat b4("Dave", 10);
		Form f1("FormA", 30, 20);
		std::cout << f1 << std::endl;
		b4.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test invalid form signing
	try
	{
		Bureaucrat b5("Eve", 50);
		Form f2("FormB", 30, 20);
		std::cout << f2 << std::endl;
		b5.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
