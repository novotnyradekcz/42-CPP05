/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:35:11 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/01 07:56:50 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " created with default grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << *this << " copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
		std::cout << *this << " assigned" << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << *this << " destroyed" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " grade set to " << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
