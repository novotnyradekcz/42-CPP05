/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:12 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/01 07:58:08 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &b);

	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _executeGrade;

		void checkGrade(int grade) const;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif