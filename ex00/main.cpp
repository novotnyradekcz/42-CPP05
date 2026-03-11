/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:40:35 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/11 19:20:41 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
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

	try
	{
		Bureaucrat b3("Charlie", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b4("Dave", 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
