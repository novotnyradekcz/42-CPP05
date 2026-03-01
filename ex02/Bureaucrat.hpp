/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:35:16 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/01 07:57:32 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &f) const;
		void executeForm(const AForm &form) const;

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

	private:
		const std::string _name;
		int _grade;
		void setGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif