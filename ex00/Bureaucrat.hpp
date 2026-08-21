#pragma once

#include <string>
#include <exception>

class Bureaucrat {
	private:
		int _grade;
		const std::string _name;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string getName();
		int	getGrade();
		
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw() {
					return "Grade too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw() {
					return "Grade too low";
				}
		};

};
