/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:27 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/01 08:00:01 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form " << _name << " created with default sign grade " << _signGrade
			  << " and default execute grade " << _executeGrade << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "Form " << _name << " created with sign grade " << _signGrade
			  << " and execute grade " << _executeGrade << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form " << _name << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		std::cout << "Form " << _name << " assigned" << std::endl;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
	std::cout << "Form " << _name << " signed by " << b.getName() << std::endl;
}

void AForm::checkGrade(int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
	executeAction();
	std::cout << executor << " executed " << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form " << f.getName() << " (sign grade: " << f.getSignGrade()
	   << ", execute grade: " << f.getExecuteGrade() << ", signed: " << (f.isSigned() ? "yes" : "no") << ")";
	return os;
}
