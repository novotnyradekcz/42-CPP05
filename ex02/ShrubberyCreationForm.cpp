/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:55:00 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/01 08:01:56 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << _target << "_shrubbery" << std::endl;
		return;
	}

	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{  #" << std::endl;
	file << "       }|{" << std::endl;
	file << std::endl;
	file << "      .@@@." << std::endl;
	file << "    .@@@@@@@@." << std::endl;
	file << "   @@@@@@@@@@@@@" << std::endl;
	file << "  @@@@@@@@@@@@@@@" << std::endl;
	file << " @@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "       ||||||" << std::endl;
	file << "       ||||||" << std::endl;

	file.close();
	std::cout << "Shrubbery has been created at " << _target << std::endl;
}
