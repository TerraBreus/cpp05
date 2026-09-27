#pragma once

#include <string>
#include <exception>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string getName() const;
		int	getGrade() const;
		
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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);
