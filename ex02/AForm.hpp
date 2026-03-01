/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:12 by rnovotny          #+#    #+#             */
/*   Updated: 2026/02/26 16:42:39 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &b);
		void execute(const Bureaucrat &executor) const;

	protected:
		virtual void executeAction() const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif