/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:27 by rnovotny          #+#    #+#             */
/*   Updated: 2026/02/26 16:44:51 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "Form " << _name << " created with sign grade " << _signGrade
			  << " and execute grade " << _executeGrade << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form " << _name << " copied" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		std::cout << "Form " << _name << " assigned" << std::endl;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
	std::cout << "Form " << _name << " signed by " << b.getName() << std::endl;
}

void Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << " (sign grade: " << f.getSignGrade()
	   << ", execute grade: " << f.getExecuteGrade() << ", signed: " << (f.isSigned() ? "yes" : "no") << ")";
	return os;
}
